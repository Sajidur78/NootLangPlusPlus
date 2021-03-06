// YeetLang++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#if WIN32
#include <windows.h>
#endif // WINDOWS

// Types
typedef unsigned char BYTE;

// Globals
static std::string output;
static std::vector<char> data;

void PrintOutput()
{
    if (output.empty())
        return;

    printf("%s\r\n", output.c_str());
    output.clear();
}

void IncDataTable(int amount)
{
    if (amount >= data.size())
    {
        for (int i = data.size(); i < amount; ++i)
            data.push_back(0);
    }
}

bool CheckString(const char* key, int index, const char* value)
{
    return !memcmp(key + index, value, strlen(value));
}

int main(int argc, const char* argv[])
{
    // Win32 Title
    #if WIN32
        SetConsoleTitle(_T("YeetLang++"));
    #endif

    // Read File
    auto handle = fopen(argv[1], "rb");
    if (!handle)
    {
        printf("File Not found");
        // Pause if compiled for Win32
        #if WIN32
            system("pause");
        #endif
        return 0;
    }
    fseek(handle, 0, SEEK_END);
    int size = ftell(handle);
    fseek(handle, 0, SEEK_SET);
    char* instructions = (char*) malloc(size);
    fread(instructions, 1, size, handle);

    int index = 0;
    int dataPointer = 0;
    int ignoreAmount = 0;
    FILE* fs = nullptr;
    data.push_back(0);
    // Main Loop
    while (index < size)
    {
        if (instructions[index] == 'y' || instructions[index] == 'Y')
        {
            if (CheckString(instructions, index, "yeeT"))
            {
                ++dataPointer;
                if (dataPointer >= data.size())
                    data.push_back(0);
            }
            else if (CheckString(instructions, index, "Yeet"))
            {
                --dataPointer;
            }
            else if (CheckString(instructions, index, "yeET"))
            {
                ++(data[dataPointer]);
            }
            else if (CheckString(instructions, index, "YEet"))
            {
                --(data[dataPointer]);
            }
            else if (CheckString(instructions, index, "yeet"))
            {
                // subscirbe to redfox comms, give a shotout to simpleflips and check ichigo's hot furry mods.. And SuperSonic16!!!!
                output.append(&data[dataPointer], 1);
            }
            else if (CheckString(instructions, index, "YEEt"))
            {
                if (data.at(dataPointer) == 0)
                {
                    while (index <= size)
                    {
                        if (CheckString(instructions, index + 4, "yEET"))
                        {
                            --ignoreAmount;
                            if (ignoreAmount <= 0)
                                break;
                        }
                        if (CheckString(instructions, index + 4, "YEEt"))
                        {
                            ++ignoreAmount;
                        }
                        index += 4;
                    }
                    ignoreAmount = 0;
                }
            }
            else if (CheckString(instructions, index, "yEET"))
            {
                if (data.at(dataPointer) != 0)
                {
                    while (index > 0)
                    {
                        if (CheckString(instructions, index + 4, "YEEt"))
                        {
                            --ignoreAmount;
                            if (ignoreAmount <= 0)
                                break;
                        }
                        if (CheckString(instructions, index + 4, "yEET"))
                        {
                            ++ignoreAmount;
                        }
                        index -= 4;
                    }
                    ignoreAmount = 0;
                }
            }
            else if (CheckString(instructions, index, "yEet"))
            {
                IncDataTable(dataPointer + 2);
                data[dataPointer] = data[dataPointer + 1] / data[dataPointer + 2];
            }
            else if (CheckString(instructions, index, "yeEt"))
            {
                IncDataTable(dataPointer + 2);
                data[dataPointer] = data[dataPointer + 1] * data[dataPointer + 2];
            }
            else if (CheckString(instructions, index, "YeeT"))
            {
                IncDataTable(dataPointer + 2);
                data[dataPointer] = data[dataPointer + 1] | data[dataPointer + 2];
            }
            else if (CheckString(instructions, index, "yEEt"))
            {
                IncDataTable(dataPointer + 2);
                data[dataPointer] = data[dataPointer + 1] & data[dataPointer + 2];
            }
            else if (CheckString(instructions, index, "YeEt"))
            {
                fread(&(data[dataPointer]), 1, 1, fs);
            }
            else if (CheckString(instructions, index, "YeET"))
            {
                fwrite(&(data[dataPointer]), 1, 1, fs);
            }
            else if (CheckString(instructions, index, "YEeT"))
            {
                printf("      .___.\n");
                printf("     /     \\\n");
                printf("    | O _ O |\n");
                printf("    /  \\_/  \\ \n");
                printf("  .' /     \\ `.\n");
                printf(" / _|  yeet |_ \\\n");
                printf("(_/ |  lang | \\_)\n");
                printf("    \\       /\n");
                printf("   __\\_>-<_/__\n");
                printf("   ~;/     \\;~\n");
                printf("\n");
                printf("why did I make this?\n");
                break;
            }
            else if (CheckString(instructions, index, "YEET"))
            {
                if (fs == nullptr)
                {
                    int e = dataPointer + data[dataPointer];
                    std::string fn;
                    
                    for (; dataPointer < e; ++dataPointer)
                    {
                        fn.append(&data[dataPointer + 1], 1);
                    }

                    dataPointer = e;
                    fs = fopen(fn.c_str(), "r+b");
                    if (fs == nullptr)
                    {
                        fs = fopen(fn.c_str(), "wb");
                    }
                }
                else
                {
                    fclose(fs);
                    fs = nullptr;
                }
            }
            index += 4;
        }
        else
        {
            printf("fineE\n");
            index += 4;
        }
    }
    PrintOutput();
    // Pause if compiled for Win32
    #if WIN32
        system("pause");
    #endif
    delete instructions;
    return 0;
}

