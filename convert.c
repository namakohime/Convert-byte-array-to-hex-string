#include <stdio.h>

int main( )
{
  FILE *fp;
  int i, size;
  unsigned char buf[1024];
  char hex_string[1024];
  
  fp = fopen("test.bmp","rb");
  if(fp != NULL) {
    size = fread( &buf, sizeof(char), 128, fp);
  }
  fclose(fp);

  for(i = 0; i < size * 2; i++) {
    sprintf(&hex_string[3 * i] , "%02X%s", buf[i], (i + 1) % 16 == 0 ? "¥n" : " ");
  }
  hex_string[size * 2] = '¥0';
  printf("%s ", hex_string);
  return 0;
}
