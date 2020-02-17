#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char header[6];
  short int width;
  short int height;
}gifHeader;
  
int main(int argc, char *argv[]){
  FILE *inFile;
  int numRead;
  gifHeader gifInfo;
  
  if (argc != 2) {
    fprintf(stderr, "Usage: %s fileName", argv[0]);
    exit(1);
  }
  
  if ((inFile = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error opening %s", argv[1]);
    exit(1);
  }

  if ((numRead = fread(&gifInfo, sizeof(gifHeader), 1, inFile)) != 1) {
    if (feof(inFile)) {
      perror(argv[1]);
    }
    else {
      fprintf(stderr, "Weird Error opening %s", argv[1]);
    }
    exit(1);
  }

  if ((strncmp("GIF87a", gifInfo.header, 6) != 0) && strncmp("GIF89a", gifInfo.header, 6) != 0) {
    fprintf(stderr, "THIS (%s) NOT A GIF\n", argv[1]);
    exit(1);
  }

  printf("FileName: %s   GIF Type: %c%c%c   Width:%d   Height:%d ", argv[1], gifInfo.header[3], gifInfo.header[4], gifInfo.header[5], gifInfo.width, gifInfo.height);

  fclose(inFile);
  
  return 0;
}
