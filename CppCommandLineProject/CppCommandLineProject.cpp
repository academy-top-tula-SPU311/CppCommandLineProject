#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

int main(int argc, char* argv[])
{
    /*for (int i{}; i < argc; i++)
        std::cout << argv[i] << "\n";*/

    /*
    -c - create
    -r - read
    -w - write
    -a - append
    */

    const char* helpText[]{ "prog <option> <file name> [write/add text]",
        "options:",
        "-c - create",
        "-r - read",
        "-w - write",
        "-a - append" };

    if (argc < 3)
    {
        for (int i{}; i < 6; i++)
            std::cout << helpText[i] << "\n";
    }
    else
    {
        char* option = new char[strlen(argv[1]) + 1];
        char* fileName = new char[strlen(argv[2]) + 1];
        FILE* file{ nullptr };

        strcpy_s(option, strlen(argv[1]) + 1, argv[1]);
        strcpy_s(fileName, strlen(argv[2]) + 1, argv[2]);

        //std::cout << option << " " << file << "\n";
        if (!strcmp(option, "-c"))
            file = fopen(fileName, "w");
        else if (!strcmp(option, "-w"))
        {
            file = fopen(fileName, "w");
            for (int i{ 3 }; i < argc; i++)
            {
                fputs(argv[i], file);
                fputc(' ', file);
            }
                
        }
        else if (!strcmp(option, "-r"))
        {
            file = fopen(fileName, "r");
            if (file)
            {
                char* buffer = new char[1024];
                while (!feof(file))
                {
                    fgets(buffer, 1024, file);
                    std::cout << buffer << "\n";
                }
            }
            else
                std::cout << "file " << fileName << " not found\n";
        }
        else if (!strcmp(option, "-a"))
        {
            file = fopen(fileName, "a");
            if (file)
            {
                fputc('\n', file);
                for (int i{ 3 }; i < argc; i++)
                {
                    fputs(argv[i], file);
                    fputc(' ', file);
                }
            }
            else
                std::cout << "file " << fileName << " not found\n";
        }
        else
        {
            std::cout << "undefined option\n";
            for (int i{}; i < 6; i++)
                std::cout << helpText[i] << "\n";
        }

        if (file)
            fclose(file);

    }

    //_getch();
}
