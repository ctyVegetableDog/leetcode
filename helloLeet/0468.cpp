//Validata IP Address (regex)

class Solution {
public:
    string validIPAddress(string IP) {
        regex re4("^((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]\\d|\\d)\\.){3}(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]\\d|\\d)");
        std:;regex re6("^([\\da-fA-F]{1,4}:){7}[\\da-fA-F]{1,4}");
        if (regex_match(IP, re4)) return "IPv4";
        else if (regex_match(IP, re6)) return "IPv6";
        else return "Neither";
    }
};
