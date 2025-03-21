#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <vector>

struct Entry {
    int id;
    std::string name;
};

class Database {
public:
    bool insert(const std::string& table, int id, const std::string& name, std::string& response) {
        auto& target = (table == "A") ? tableA_ : tableB_;

        if (target.count(id)) {
            response = "ERR duplicate " + std::to_string(id) + "\n";
            return false;
        }

        target[id] = name;
        response = "OK\n";
        return true;
    }

    void truncate(const std::string& table, std::string& response) {
        if (table == "A") {
            tableA_.clear();
        } else {
            tableB_.clear();
        }

        response = "OK\n";
    }

    std::string intersection() {
        std::ostringstream oss;

        for (const auto& [id, name] : tableA_) {
            if (tableB_.count(id)) {
                oss << id << "," << name << "," << tableB_[id] << "\n";
            }
        }

        return oss.str() + "OK\n";
    }

    std::string symmetric_difference() {
        std::ostringstream oss;
        std::set<int> ids;

        for (const auto& [id, _] : tableA_) ids.insert(id);
        for (const auto& [id, _] : tableB_) ids.insert(id);

        for (int id : ids) {
            bool inA = tableA_.count(id), inB = tableB_.count(id);
            if (inA && inB) continue;

            oss << id << "," << (inA ? tableA_[id] : "") << "," << (inB ? tableB_[id] : "") << "\n";
        }
        
        return oss.str() + "OK\n";
    }

private:
    std::unordered_map<int, std::string> tableA_, tableB_;
};
