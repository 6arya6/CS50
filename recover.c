#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Defining a byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Checking if user input is valid
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    //Initialising variables
    BYTE buffer[512];
    int i = 0;
    char jpg_file[8];
    FILE *img = NULL;

    //Repeatedly reading a chunk into a buffer
    while (fread(&buffer, 512, 1, file) == 1)
    {
        //Checking if this is the satrt of a new jpg file
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            // If not first JPEG, close previous
            if (!(i == 0))
            {
                fclose(img);
            }
            //Initialize file
            sprintf(jpg_file, "%03i.jpg", i);
            img = fopen(jpg_file, "w");
            i++;

        }
        //If jpg has been found
        if (!(i == 0))
        {
            fwrite(&buffer, 512, 1, img);
        }
    }
    //Closing all files
    fclose(img);
    fclose(file);
}