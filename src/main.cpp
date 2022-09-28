#include <iostream>
#include <fstream>

typedef unsigned int DWORD;

// https://gtamods.com/wiki/Saves_(GTA_SA)#Block_0:_Simple_Vars
struct simples_vars {
    DWORD version_id;
    char save_name[100];
    uint8_t mission_pack;
    uint8_t align[3];
    DWORD current_town;
    float camera_pos[3];
    DWORD ingame_minute;
    DWORD weather_timer;
    uint8_t ingame_month;
    uint8_t ingame_month_day;
    uint8_t hour;
    uint8_t minute;
} save_file;

int main(int argc, char** argv)
{
    if (argv[1] == nullptr) {
        std::cout << "USAGE: program [FILE PATH]" << std::endl;
        return EXIT_FAILURE;
    }

    char* file_path = argv[1];

    std::ifstream file(file_path, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        file.read((char*)&save_file, sizeof(save_file));

        file.close();
    }

    std::cout << save_file.save_name << std::endl;

    return EXIT_SUCCESS;
}