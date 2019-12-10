#include "../include/kstdio.h"
#include "../include/def.h"
#include "../include/comfunc.h"

// The VGA framebuffer starts at 0xB8000.
UINT16 *video_memory = (UINT16 *)0xB8000;

// Stores the cursor position.
UINT8 cursor_x = 0;
UINT8 cursor_y = 0; 

static VOID mvcursor ()
{
   UINT16 crsrloc = cursor_y * 80 + cursor_x;
   outb(0x3D4, 14);           // Tell the VGA board we are setting the high cursor byte.
   outb(0x3D5, crsrloc >> 8); // Send the high cursor byte.
   outb(0x3D4, 15);           // Tell the VGA board we are setting the low cursor byte.
   outb(0x3D5, crsrloc);      // Send the low cursor byte.
}

static VOID scroll ()
{
    // Get a space character with the default colour attributes.
    UINT8 attributeByte = (0 << 4) | (15 & 0x0F);
    UINT16 blank = 0x20 | (attributeByte << 8);

    // Row 25 is the end, this means we need to scroll up
    if(cursor_y >= 25)
    {
        // Move the current text chunk that makes up the screen
        // back in the buffer by a line
        int i;
        for (i = 0*80; i < 24*80; i++)
        {
            video_memory[i] = video_memory[i+80];
        }

        // The last line should now be blank. Do this by writing
        // 80 spaces to it.
        for (i = 24*80; i < 25*80; i++)
        {
            video_memory[i] = blank;
        }
        // The cursor should now be on the last line.
        cursor_y = 24;
    }
}

VOID kput (CHAR c)
{
    // The background colour is black (0), the foreground is white (15).
    UINT8 backColour = 0;
    UINT8 foreColour = 15;

    // The attribute byte is made up of two nibbles - the lower being the 
    // foreground colour, and the upper the background colour.
    UINT8  attributeByte = (backColour << 4) | (foreColour & 0x0F);
    // The attribute byte is the top 8 bits of the word we have to send to the
    // VGA board.
    UINT16 attribute = attributeByte << 8;
    UINT16 *location;

    // Handle a backspace, by moving the cursor back one space
    if (c == 0x08 && cursor_x)
    {
        cursor_x--;
    }

    // Handle a tab by increasing the cursor's X, but only to a point
    // where it is divisible by 8.
    else if (c == 0x09)
    {
        cursor_x = (cursor_x+8) & ~(8-1);
    }

    // Handle carriage return
    else if (c == '\r')
    {
        cursor_x = 0;
    }

    // Handle newline by moving cursor back to left and increasing the row
    else if (c == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }
    // Handle any other printable character.
    else if(c >= ' ')
    {
        location = video_memory + (cursor_y*80 + cursor_x);
        *location = c | attribute;
        cursor_x++;
    }

    // Check if we need to insert a new line because we have reached the end
    // of the screen.
    if (cursor_x >= 80)
    {
        cursor_x = 0;
        cursor_y ++;
    }

    // Scroll the screen if needed.
    scroll ();
    // Move the hardware cursor.
    mvcursor ();
}

VOID kprintf (CHAR *c)
{
    int i = 0;
    while (c[i])
    {
        kput (c[i++]);
    }
}

VOID kclear (VOID) 
{
    // Make an attribute byte for the default colours
    UINT8 attributeByte = (0 << 4) | (15 & 0x0F);
    UINT16 blank = 0x20 | (attributeByte << 8);

    int i;
    for (i = 0; i < 80*25; i++)
    {
        video_memory[i] = blank;
    }

    // Move the hardware cursor back to the start.
    cursor_x = 0;
    cursor_y = 0;
    mvcursor ();
}
