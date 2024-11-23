#include <bits/stdc++.h>
using namespace std;

struct Event {
    string id;
    string title;
    string acronym;
    string projectCode;
    string projectCode3;
    string recordType;
    string parentID;
};

bool compareEvents(const Event &a, const Event &b) {
    if (a.title == b.title)
        return a.id < b.id;
    return a.title < b.title;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<Event> events;
    unordered_map<string, vector<Event>> parentChildrenMap;
    unordered_map<string, Event> eventMap;
    
    // Read and parse CSV input
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        Event event;
        getline(iss, event.id, ',');
        
        getline(iss, event.title, '"');
        getline(iss, event.title, '"');
        
        getline(iss, event.acronym, ',');
        getline(iss, event.projectCode, ',');
        getline(iss, event.projectCode3, ',');
        getline(iss, event.recordType, ',');
        
        // Exclude records without acronym
        if (event.acronym.empty()) continue;
        
        events.push_back(event);
        eventMap[event.id] = event;
        
        // Organize events by acronym
        if (event.recordType == "Parent Event") {
            parentChildrenMap[event.acronym].push_back(event);
        }
    }
    
    // Connect children with their parents
    for (auto &event : events) {
        if (event.recordType == "IEEE Event") {
            string parentAcronym = event.acronym;
            
            if (parentChildrenMap[parentAcronym].size() == 1) {
                string parentID = parentChildrenMap[parentAcronym][0].id;
                event.parentID = parentID;
                parentChildrenMap[parentAcronym].push_back(event);
            }
        }
    }
    
    // Filter out invalid sets and process 3 Digit Project Code for parents
    vector<Event> resultParents;
    for (auto &entry : parentChildrenMap) {
        auto &setEvents = entry.second;
        
        if (setEvents.size() <= 1) continue; // Exclude parents with no children
        
        string common3DigitCode = setEvents[1].projectCode3;
        bool consistentCode = true;
        
        for (size_t i = 2; i < setEvents.size(); ++i) {
            if (setEvents[i].projectCode3 != common3DigitCode) {
                consistentCode = false;
                break;
            }
        }
        
        if (!consistentCode) {
            setEvents[0].projectCode3 = "???";
        } else {
            setEvents[0].projectCode3 = common3DigitCode;
        }
        
        resultParents.push_back(setEvents[0]);
    }
    
    // Sort and print results
    sort(resultParents.begin(), resultParents.end(), [](const Event &a, const Event &b) {
        return a.acronym < b.acronym;
    });
    
    for (const auto &parent : resultParents) {
        cout << parent.id << ",\"" << parent.title << "\",\"" << parent.acronym << "\",,"
             << parent.projectCode3 << "," << parent.recordType << "\n";
        
        auto &children = parentChildrenMap[parent.acronym];
        sort(children.begin() + 1, children.end(), compareEvents);
        
        for (size_t i = 1; i < children.size(); ++i) {
            cout << children[i].id << ",\"" << children[i].title << "\",\"" << children[i].acronym
                 << "\"," << children[i].projectCode << "," << children[i].projectCode3 << ","
                 << children[i].recordType << "," << parent.id << "\n";
        }
    }

    return 0;
}
