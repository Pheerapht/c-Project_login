#include <iostream>
#include <string>
#include <unordered_map>

// Stage 1: Prompt the user for a username
std::string stage1() {
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;
    return username;
}

// Stage 2: Prompt the user for a password
std::string stage2() {
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;
    return password;
}

// Stage 3: Check the entered credentials against a stored list of valid credentials
bool stage3(const std::string& username, const std::string& password) {
    // Create a map of valid usernames and passwords
    std::unordered_map<std::string, std::string> credentials = {
        {"alice", "password123"},
        {"bob", "letmein"}
    };

    // Check the entered credentials against the stored credentials
    if (credentials.count(username) > 0 && credentials[username] == password) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Run the login pipeline
    std::string username = stage1();
    std::string password = stage2();
    bool is_valid = stage3(username, password);

    // Print the result of the login attempt
    if (is_valid) {
        std::cout << "Login successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return 0;
}
