#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool __cdecl x(char *a1, unsigned int *a2)
{
  char v2; // cl

  v2 = *a1 % 2;
  if ( !v2 && (*a1 ^ 0x20) == *a2 )
    return 1;
  return v2 == 1 && (*a1 ^ 0x52) == *a2;
}

bool __cdecl y(char *a1, unsigned int *a2)
{
  int i; // [esp+0h] [ebp-Ch]
  unsigned int v4; // [esp+8h] [ebp-4h]

  v4 = a1[1] | (unsigned int)(*a1 << 8);	// v4 = a1[1] | (a1[0] << 8);
  for ( i = 1; i <= 5; ++i )
    v4 = (((int)v4 >> (16 - i)) | (v4 << i)) ^ 0x1693;
  return *a2 == v4;
}

bool __cdecl z(char *a1, unsigned int *a2)
{
  char v3[68]; // [esp+0h] [ebp-64h] BYREF
  int v4; // [esp+44h] [ebp-20h]
  int v5; // [esp+48h] [ebp-1Ch]
  int v7; // [esp+50h] [ebp-14h]
  int i; // [esp+54h] [ebp-10h]
  int v9; // [esp+58h] [ebp-Ch]
  unsigned int v10; // [esp+5Ch] [ebp-8h]
  unsigned int v11; // [esp+5Dh] [ebp-7h]
  unsigned int v12; // [esp+5Eh] [ebp-6h]
  char v13; // [esp+5Fh] [ebp-5h]
  char v14; // [esp+60h] [ebp-4h]
  char v15; // [esp+61h] [ebp-3h]
  char v16; // [esp+62h] [ebp-2h]

  v9 = 0;
  i = 0;
  v7 = 3;
  v5 = 0;
  v4 = 0;
  memcpy(v3, "ABDCEHGFIJKLUNOPYRTSMVWXQZajcdefohibkmlngpqrstuv4xzy8123w56709+0", 64);
  while ( v7-- )
  {
    *(&v14 + v9++) = *a1++;
    if ( v9 == 3 )
    {
      v10 = (v14 & 0xFC) >> 2;
      if ( (char)v3[v10] != *a2 )
        return 0;
      v11 = ((v15 & 0xF0) >> 4) + 16 * (v14 & 3);
      if ( (char)v3[v11] != a2[1] )
        return 0;
      v12 = ((v16 & 0xC0) >> 6) + 4 * (v15 & 0xF);
      if ( (char)v3[v12] != a2[2] )
        return 0;
      v13 = v16 & 0x3F;
      if ( (char)v3[v16 & 0x3F] != a2[3] )
        return 0;
      v9 = 0;
    }
  }
  if ( v9 <= 0 )
    return 1;
  for ( i = v9; i < 3; ++i )
    *(&v14 + i) = 0;
  v10 = (v14 & 0xFC) >> 2;
  if ( (char)v3[v10] != *a2 )
    return 0;
  v11 = ((v15 & 0xF0) >> 4) + 16 * (v14 & 3);
  if ( (char)v3[v11] != a2[1] )
    return 0;
  v12 = ((v16 & 0xC0) >> 6) + 4 * (v15 & 0xF);
  if ( (char)v3[v12] != a2[2] )
    return 0;
  v13 = v16 & 0x3F;
  return (char)v3[v16 & 0x3F] == a2[3];
}

int __cdecl t(char *a1, int a2, int a3)
{
  char v4[256]; // [esp+0h] [ebp-11Ch] BYREF

  void (__cdecl *v6)(char *, char *); // [esp+104h] [ebp-18h]
  int (__cdecl *v5)(char *, char *, int); // [esp+100h] [ebp-1Ch]
  char v7[8]; // [esp+108h] [ebp-14h] BYREF
  char v8[11]; // [esp+110h] [ebp-Ch] BYREF

  strcpy(v8, "susan");
  v6 = *(void (__cdecl **)(char *, char *))(a3 + 4);
  v5 = *(int (__cdecl **)(char *, char *, int))(a3 + 8);
  v6(v8, v4);
  v7[0] = *a1;
  v7[1] = a1[1];
  v7[2] = a1[2];
  v7[3] = a1[3];
  v7[4] = 0;
  return v5(v4, v7, a2);
}

int main(){
	char s[] = "t\xcc\xcc\xcc\x01\x00\x00\x00\x01\x00\x00\x00H\xcc\xcc\xcc\x01\x00\x00\x00\x02\x00\x00\x00;\xcc\xcc\xcc\x02\x00\x00\x00\x88\x00\x00\x00\x81$\xcc\xcc\x03\x00\x00\x00o\x00\x00\x00c3Yo\x02\x00\x00\x00\x84\x00\x00\x00\x01\x01\xcc\xcc\x02\x00\x00\x00\n\x00\x00\x005\xaf\xcc\xcc\x01\x00\x00\x00\xd0\x00\x00\x003\xcc\xcc\xcc\x03\x00\x00\x00\x0f\x00\x00\x00dMxv\x04\x00\x00\x00\x12\x00\x00\x00\xdd \xb1\x1a\x01\x00\x00\x00\x06\x01\x00\x00\x0c\xcc\xcc\xcc\x03\x00\x00\x00\xe8\x00\x00\x00jDB5\x02\x00\x00\x00\x1d\x00\x00\x00\xa6!\xcc\xcc\x02\x00\x00\x00\x1f\x00\x00\x00\xbe\x8a\xcc\xcc\x01\x00\x00\x00!\x00\x00\x00L\xcc\xcc\xcc\x02\x00\x00\x00\"\x00\x00\x00&\x0e\xcc\xcc\x01\x00\x00\x00$\x00\x00\x005\xcc\xcc\xcc\x01\x00\x00\x00]\x00\x00\x00;\xcc\xcc\xcc\x03\x00\x00\x00+\x00\x00\x00jE9u\x04\x00\x00\x00\x16\x00\x00\x00\x88?\xed\r\x03\x00\x00\x00\xeb\x00\x00\x00j3Vz\x02\x00\x00\x002\x00\x00\x005\xaf\xcc\xcc\x02\x00\x00\x000\x00\x00\x00\xab/\xcc\xcc\x02\x00\x00\x00\x08\x00\x00\x00\x816\xcc\xcc\x03\x00\x00\x004\x00\x00\x00jlcu\x01\x00\x00\x007\x00\x00\x00\x00\xcc\xcc\xcc\x02\x00\x00\x008\x00\x00\x00%<\xcc\xcc\x03\x00\x00\x00S\x00\x00\x00IFRg\x01\x00\x00\x00>\x00\x00\x00!\xcc\xcc\xcc\x01\x00\x00\x00?\x00\x00\x00T\xcc\xcc\xcc\x01\x00\x00\x00\x92\x00\x00\x007\xcc\xcc\xcc\x01\x00\x00\x00\x86\x00\x00\x00t\xcc\xcc\xcc\x04\x00\x00\x00\t\x01\x00\x00\xc06\xfd\x13\x01\x00\x00\x00J\x00\x00\x00\x00\xcc\xcc\xcc\x01\x00\x00\x00\r\x01\x00\x00R\xcc\xcc\xcc\x04\x00\x00\x00M\x00\x00\x00\xc1=\xbaC\x03\x00\x00\x00\x1c\x01\x00\x00d2wo\x04\x00\x00\x00:\x00\x00\x00\xcds\xb0\x0c\x04\x00\x00\x00V\x00\x00\x00\xcds\xb9\x06\x03\x00\x00\x00Z\x00\x00\x00Q2my\x04\x00\x00\x00\x0f\x01\x00\x00\xcb6\xae\x10\x01\x00\x00\x00^\x00\x00\x00=\xcc\xcc\xcc\x02\x00\x00\x00_\x00\x00\x00\x01!\xcc\xcc\x04\x00\x00\x00h\x00\x00\x00\x88\'\xb5\x06\x01\x00\x00\x00\xba\x00\x00\x00D\xcc\xcc\xcc\x04\x00\x00\x00\x9a\x00\x00\x00\xdc:\xba\x06\x03\x00\x00\x00l\x00\x00\x00IFJm\x04\x00\x00\x00\x04\x00\x00\x00\x88b\xaeC\x04\x00\x00\x00r\x00\x00\x00\xc1 \xfd\x0e\x02\x00\x00\x00\xc7\x00\x00\x00=\x86\xcc\xcc\x01\x00\x00\x00z\x00\x00\x00+\xcc\xcc\xcc\x04\x00\x00\x00{\x00\x00\x00\x88\'\xb8\r\x01\x00\x00\x00\xc6\x00\x00\x00\x0e\xcc\xcc\xcc\x01\x00\x00\x00\x83\x00\x00\x00+\xcc\xcc\xcc\x01\x00\x00\x00\x03\x00\x00\x00\x01\xcc\xcc\xcc\x04\x00\x00\x00\x93\x00\x00\x00\x88#\xbc\x13\x04\x00\x00\x00\xa9\x00\x00\x00\x887\xb2C\x03\x00\x00\x00\x0c\x00\x00\x00ZGmC\x04\x00\x00\x00\x8a\x00\x00\x00\xce6\xbc\x11\x04\x00\x00\x00\x8e\x00\x00\x00\xdbs\xbc\x11\x04\x00\x00\x00\xaf\x00\x00\x00\xd1\'\xb5\n\x02\x00\x00\x00D\x00\x00\x00%\xa5\xcc\xcc\x01\x00\x00\x00\x97\x00\x00\x007\xcc\xcc\xcc\x02\x00\x00\x00\x98\x00\x00\x00\x01/\xcc\xcc\x04\x00\x00\x00a\x00\x00\x00\xdc<\xfd\x02\x01\x00\x00\x00\x9e\x00\x00\x00R\xcc\xcc\xcc\x04\x00\x00\x00\x9f\x00\x00\x00\xdb}\xfd:\x04\x00\x00\x00F\x00\x00\x00\xcb&\xb1\x17\x01\x00\x00\x00\xa7\x00\x00\x003\xcc\xcc\xcc\x01\x00\x00\x00/\x00\x00\x00\x00\xcc\xcc\xcc\x01\x00\x00\x00\x87\x00\x00\x00H\xcc\xcc\xcc\x01\x00\x00\x00\xad\x00\x00\x003\xcc\xcc\xcc\x01\x00\x00\x00\xae\x00\x00\x00N\xcc\xcc\xcc\x04\x00\x00\x00\xc9\x00\x00\x00\xc7&\xfd\x00\x02\x00\x00\x00\xb3\x00\x00\x00\"\xa1\xcc\xcc\x01\x00\x00\x00\xb5\x00\x00\x00\x00\xcc\xcc\xcc\x04\x00\x00\x00\xb6\x00\x00\x00\xd1<\xa8C\x03\x00\x00\x00e\x00\x00\x00Q3Ys\x01\x00\x00\x00\xbb\x00\x00\x007\xcc\xcc\xcc\x01\x00\x00\x00\xbc\x00\x00\x001\xcc\xcc\xcc\x04\x00\x00\x00\xd2\x00\x00\x00\xdcs\xa9\x0c\x03\x00\x00\x00\xbf\x00\x00\x00ZTB8\x02\x00\x00\x00\xc2\x00\x00\x00\x81!\xcc\xcc\x01\x00\x00\x00\xda\x00\x00\x00N\xcc\xcc\xcc\x04\x00\x00\x00\x7f\x00\x00\x00\xc90\xb4\x17\x04\x00\x00\x00v\x00\x00\x00\xcd!\xb8\x0f\x04\x00\x00\x00\xfb\x00\x00\x00\xcds\xad\x11\x02\x00\x00\x00\xcd\x00\x00\x00\xa6&\xcc\xcc\x01\x00\x00\x00\xcf\x00\x00\x00\x00\xcc\xcc\xcc\x02\x00\x00\x00K\x00\x00\x00%,\xcc\xcc\x01\x00\x00\x00\xd1\x00\x00\x001\xcc\xcc\xcc\x02\x00\x00\x00\xbd\x00\x00\x00\xa3\"\xcc\xcc\x03\x00\x00\x00\x13\x01\x00\x00IGmy\x02\x00\x00\x00\xc4\x00\x00\x00&\xa4\xcc\xcc\x03\x00\x00\x00\xef\x00\x00\x00jGml\x04\x00\x00\x00\xdc\x00\x00\x00\xcds\xbc\r\x01\x00\x00\x00\xee\x00\x00\x00\x00\xcc\xcc\xcc\x04\x00\x00\x00\xe4\x00\x00\x00\xc6\'\xaf\x0c\x03\x00\x00\x00\x1a\x00\x00\x00Z19U\x01\x00\x00\x00.\x00\x00\x005\xcc\xcc\xcc\x04\x00\x00\x00\xe0\x00\x00\x00\xccs\xbe\x0c\x01\x00\x00\x00\xdb\x00\x00\x005\xcc\xcc\xcc\x02\x00\x00\x00\xf2\x00\x00\x00\x8c\xa4\xcc\xcc\x04\x00\x00\x00\xf4\x00\x00\x00\x882\xb3\x07\x02\x00\x00\x00%\x00\x00\x00\xa79\xcc\xcc\x04\x00\x00\x00@\x00\x00\x00\x887\xb4\x05\x01\x00\x00\x00\xff\x00\x00\x00=\xcc\xcc\xcc\x03\x00\x00\x00\x00\x01\x00\x00Q2Vk\x03\x00\x00\x00\x03\x01\x00\x00dXJm\x04\x00\x00\x00\'\x00\x00\x00\xc7\x1d\xba<\x02\x00\x00\x00\x07\x01\x00\x00+\x06\xcc\xcc\x04\x00\x00\x00\xa3\x00\x00\x00\xc7&\xfd\x00\x01\x00\x00\x00\xa8\x00\x00\x00N\xcc\xcc\xcc\x01\x00\x00\x00\x0e\x01\x00\x00=\xcc\xcc\xcc\x03\x00\x00\x00\xf8\x00\x00\x00IFRg\x04\x00\x00\x00\xd6\x00\x00\x00\x880\xb5\x02\x02\x00\x00\x00\x16\x01\x00\x00%\x86\xcc\xcc\x04\x00\x00\x00\x18\x01\x00\x00\xdc \xfd\x0c\x02\x00\x00\x00Q\x00\x00\x00\xa8\xa2\xcc\xcc\x03\x00\x00\x00\x1f\x01\x00\x00clV3\x03\x00\x00\x00\"\x01\x00\x00QXJk\x01\x00\x00\x00%\x01\x00\x00\x0e\xcc\xcc";
	printf("%d", s[4]); //4 8 16 28 40 52 64(+12)
	char x[] = "ab";
}

