#ifndef MD_STR_TABLE_H
#define MD_STR_TABLE_H

/*
    The best way I could think of was to create a large table
    that has 64 entries. Since at most with 2.0 there can be
    a maximum of 64 tables. At this time not all of these are
    used. So I only populate the indexes that are for a specific
    table.
 
    What I do is describe the fields in a row for each table. Since
    each table has different fields per row each entry is different.
    Also, most of the fields are index types. And since the index
    size can change to, apparently conserve space, I use these identifiers
    so that when I actually go to use them I calculate their size before
    hand. The '1', '2', and '4' are always this size.
 
    1 - 8 bit field
    2 - 16 bit field
    4 - 32 bit field
    S - index to String table
    G - index to GUID table
    R - resolution scope index (Module, ModuleRef, AssemblyRef, TypeRef)
    T - TypeDefOrRef index (TypeRef, TypeDef, TypeSpec)
    F - Field table index
    M - MethodDef table index
    B - Blob table index
    P - Param table index
    D - TypeDef table index (different from T)
    E - MemberRefParent index (TypeRef, ModuleRef, MethodDef, TypeSpec, TypeDef)
    H - HasConstant index (Param, Field, Property)
    C - HasCustomAttribute index (**AnyTable** Except It's Self)
    I - CustomAttributeType index (MethodDef, MethodRef)
    O - HasFieldMarshal index (Field, Param)
    A - HasDesclSecurityIndex (TypeDef, MethodDef, Assembly)
    V - Event table index
    Y - Property table index
    S - HasSemantics index (Event, Property)
    U - MemberForwarded index (Field, MethodDef)
    B - Implementation index (File, AssemblyRef, ExportedType)
    X - CustomAttributeType index (MethodDef, MethodRef)
    W - ResolutionScope index (Module, ModuleRef, AssemblyRef, TypeRef)
    N - ModuleRef table index
    J - AssemblyRef table index
    K - TypeOrMethodDef index (TypeDef, MethodDef)
    L - GenericParam table index
*/
 
/*
    This is the table's ID.
*/
#define CLR20_META_TMODULE      0
#define CLR20_META_TTYPEREF     1
#define CLR20_META_TTYPEDEF     2
#define CLR20_META_TFIELD       4
#define CLR20_META_TMETHODDEF       6
#define CLR20_META_TPARAM       8
#define CLR20_META_TIFACEIMPL       9   /* interface implementation table */
#define CLR20_META_TMEMBERREF       10
#define CLR20_META_TCONSTANT        11
#define CLR20_META_TCUSTOMATTRI     12
#define CLR20_META_TFIELDMARSHAL    13
#define CLR20_META_TDECLSECURITY    14
#define CLR20_META_TCLASSLAYOUT     15
#define CLR20_META_TFIELDLAYOUT     16
#define CLR20_META_TSTANDALONGSIG   17
#define CLR20_META_TEVENTMAP        18
#define CLR20_META_TEVENT       20
#define CLR20_META_TPROPERTY        23
#define CLR20_META_TMETHODSEMAN     24
#define CLR20_META_TMETHODIMPL      25
#define CLR20_META_TMODULEREF       26
#define CLR20_META_TIMPLMAP     28
#define CLR20_META_TFIELDRVA        29
#define CLR20_META_TASSEMBLY        32
#define CLR20_META_TASSEMBLYPROC    33
#define CLR20_META_TASSEMBLYOS      34
#define CLR20_META_TASSEMBLYREF     35
#define CLR20_META_TASSEMBLYREFPROC 36
#define CLR20_META_TASSEMBLYREFOS   37
#define CLR20_META_TFILE        38
#define CLR20_META_TEXPORTEDTYPE    39
#define CLR20_META_TMANIFESTRES     40
#define CLR20_META_TNESTEDCLASS     41
#define CLR20_META_TGENERICPARAM    42
#define CLR20_META_TGENERICPARAMCONST   44  /* generic parameter contraint */
#define CLR20_META_TPROPERTYMAP     21
#define CLR20_META_TTYPESPEC        27
#define CLR20_META_TMETHODREF       63  /* WHERE IS THIS ONE??? */
 
/*
    This is the field description structure. It is created at
    compile time and is accessed during run-time to determine
    the row length so that it can be copied into a more suitable
    structure for dynamic access.
*/
uint8_t *WIN_CLR20_META_TFIELDS[64] = 
{
    [CLR20_META_TMODULE] =      "2SGGG",
    [CLR20_META_TTYPEREF] =     "RSS",      /* META_TTYPEREF */
    [CLR20_META_TTYPEDEF] =     "4SSTFM",   /* META_TTYPEDEF */
    [CLR20_META_TFIELD] =       "2SB",      /* META_TFIELD */
    [CLR20_META_TMETHODDEF] =   "422SBP",   /* META_TMETHODDEF */
    [CLR20_META_TPARAM] =       "22S",      /* META_TPARAM */
    [CLR20_META_TIFACEIMPL] =   "DT",       /* META_TIFACEIMPL */
    [CLR20_META_TMEMBERREF] =   "ESB",      /* META_TMEMBERREF */
    [CLR20_META_TCONSTANT] =    "11HB",     /* META_TCONSTANT */
    [CLR20_META_TCUSTOMATTRI] =     "CIB",      /* META_TCUSTOMATTRI */
    [CLR20_META_TFIELDMARSHAL] =    "OB",       /* META_TFIELDMARSHAL */
    [CLR20_META_TDECLSECURITY] =    "2AB",      /* META_TDECLSECURITY */
    [CLR20_META_TCLASSLAYOUT] =     "24D",      /* META_TCLASSLAYOUT */
    [CLR20_META_TFIELDLAYOUT] =     "4F",
    [CLR20_META_TSTANDALONGSIG] =   "B",
    [CLR20_META_TEVENTMAP] =    "DV",
    [CLR20_META_TEVENT] =       "2ST",
    [CLR20_META_TPROPERTYMAP] = "DY",
    [CLR20_META_TPROPERTY] =    "2SB",
    [CLR20_META_TMETHODSEMAN] = "2MS",
    [CLR20_META_TMETHODIMPL] =  "DII",
    [CLR20_META_TMODULEREF] =   "S",
    [CLR20_META_TTYPESPEC] =    "B",
    [CLR20_META_TIMPLMAP] =     "2USN",
    [CLR20_META_TFIELDRVA] =    "4F",
    [CLR20_META_TASSEMBLY] =    "422224BSS",
    [CLR20_META_TASSEMBLYPROC] =    "4",
    [CLR20_META_TASSEMBLYOS] =  "444",
    [CLR20_META_TASSEMBLYREF] =     "22224BSSB",
    [CLR20_META_TASSEMBLYREFPROC] = "4J",
    [CLR20_META_TASSEMBLYREFOS] =   "444J",
    [CLR20_META_TFILE] =        "4SB",
    [CLR20_META_TEXPORTEDTYPE] =    "44SSB",
    [CLR20_META_TMANIFESTRES] =     "44SB",
    [CLR20_META_TNESTEDCLASS] =     "DD",
    [CLR20_META_TGENERICPARAM] =    "22KS",
    [CLR20_META_TGENERICPARAMCONST]="LT"
};

#endif