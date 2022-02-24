#include <iostream>
#include <fstream>
#include "src/replace.h"
#include "template_files/main_template.h"
#include "template_files/cmake_template.h"
#include "template_files/wait_template.h"

#ifdef _WIN32

#define TEMPLATE_MBED_OS_PATH "C:\\MinGW\\Template\\mbed-os"
#define TEMPLATE_VSCODE_PATH "C:\\MinGW\\Template\\.vscode"

#else

#define TEMPLATE_MBED_OS_PATH "~/Public/Template/mbed-os"
#define TEMPLATE_VSCODE_PATH "~/Public/Template/.vscode"

#endif

int main()
{
    std::string project_name;

    std::string target_path;
    std::string new_target_path;
    std::string target_mbed_os_path;
    std::string target_main_path;
    std::string target_cmake_path;
    std::string target_vscode_path;
    std::string target_wait_h_path;
    std::string target_wait_cpp_path;


    std::string cmd_of_link_mbed_os;
    std::string cmd_of_link_vscode;
    std::string cmd_of_rename;
    std::string cmd_of_mkdir_build;
    std::string cmd_of_mkdir_lib_inc;
    std::string cmd_of_mkdir_lib_src;

    std::cout << "Please drag the project folder inside:" << std::endl;
    std::cin >> target_path;
    std::cout << std::endl << std::endl << std::endl;

#ifdef _WIN32

    target_mbed_os_path = target_path + "\\mbed-os";
    target_main_path = target_path + "\\main.cpp";
    target_cmake_path = target_path + "\\CMakeLists.txt";
    target_vscode_path = target_path + "\\.vscode";
    target_wait_h_path = target_path + "\\lib\\inc\\wait.h";
    target_wait_cpp_path = target_path + "\\lib\\src\\wait.cpp";

    cmd_of_link_mbed_os = "mklink /j " + target_mbed_os_path + " " + TEMPLATE_MBED_OS_PATH + " > nul";
    cmd_of_link_vscode = "mklink /j " + target_vscode_path + " " + TEMPLATE_VSCODE_PATH + " > nul";

    cmd_of_mkdir_build = std::string() + "mkdir " + target_path + "\\BUILD";
    cmd_of_mkdir_lib_inc = std::string() + "mkdir " + target_path + "\\lib\\inc";
    cmd_of_mkdir_lib_src = std::string() + "mkdir " + target_path + "\\lib\\src";

#else

    target_mbed_os_path = target_path + "/mbed-os";
    target_main_path = target_path + "/main.cpp";
    target_cmake_path = target_path + "/CMakeLists.txt";
    target_vscode_path = target_path + "/.vscode";
    target_wait_h_path = target_path + "/lib/inc/wait.h";
    target_wait_cpp_path = target_path + "/lib/src/wait.cpp";

    cmd_of_link_mbed_os = std::string() + "ln -s " + TEMPLATE_MBED_OS_PATH + " " + target_mbed_os_path;
    cmd_of_link_vscode = std::string() + "ln -s " + TEMPLATE_VSCODE_PATH + " " + target_vscode_path;

    cmd_of_mkdir_build = std::string() + "mkdir " + target_path + "/BUILD";
    cmd_of_mkdir_lib_inc = std::string() + "mkdir -p " + target_path + "/lib/inc";
    cmd_of_mkdir_lib_src = std::string() + "mkdir -p " + target_path + "/lib/src";

#endif

    system(cmd_of_link_mbed_os.c_str());
    system(cmd_of_link_vscode.c_str());
    system(cmd_of_mkdir_build.c_str());
    system(cmd_of_mkdir_lib_inc.c_str());
    system(cmd_of_mkdir_lib_src.c_str());

    std::ofstream main_file(target_main_path);
    main_file << main_template;

    std::cout << "What is the name of the project?" << std::endl;
    std::cin >> project_name;
    std::ofstream cmake_file(target_cmake_path);
    std::string cmake_script = replace(cmake_template, "Template", project_name.c_str());
    cmake_file << cmake_script;

    std::ofstream wait_h(target_wait_h_path);
    wait_h << wait_h_template;

    std::ofstream wait_cpp(target_wait_cpp_path);
    wait_cpp << wait_cpp_template;

    main_file.close();
    cmake_file.close();
    wait_h.close();
    wait_cpp.close();

#ifdef _WIN32

    cmd_of_rename = "ren " + target_path + " " + project_name;

#else

    new_target_path = replace_dir(target_path, project_name);
    cmd_of_rename = "mv " + target_path + " " + new_target_path;

#endif


    std::cout << cmd_of_rename;

    system(cmd_of_rename.c_str());

    return 0;
}
