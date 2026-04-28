#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
 * Activity: Emergency Room Triage System
 *
 * You're a software engineer at a hospital. The ER needs a patient
 * management system. Patients arrive at different times but must be
 * treated in order of medical severity — not arrival order.
 *
 * Severity:  1 = Critical (life-threatening)
 *            2 = Urgent   (serious condition)
 *            3 = Moderate (needs attention)
 *            4 = Minor    (can wait)
 */

struct Patient {
    string name;
    int severity;    // 1 = most critical
    int arrivalTime;
};

// TODO: buildTriageQueue  -- load all patients into an ERQueue
// TODO: peekNext          -- return name of highest-priority patient (no remove)
// TODO: treatNext         -- remove and return highest-priority patient
// TODO: treatmentOrder    -- return all names in treatment order
// TODO: hasCritical       -- true if any severity-1 patient is waiting

vector<Patient> waiting_room = {
    {"Alice",  3,  1},   // Moderate,  arrived at t=1
    {"Bob",    1,  2},   // Critical,  arrived at t=2
    {"Carol",  4,  3},   // Minor,     arrived at t=3
    {"Dave",   2,  4},   // Urgent,    arrived at t=4
    {"Eve",    1,  5},   // Critical,  arrived at t=5
    {"Frank",  3,  6},   // Moderate,  arrived at t=6
    {"Grace",  2,  7},   // Urgent,    arrived at t=7
};

class compareBySeverity{
    public:
        bool operator()(const Patient& p1, const Patient& p2){
            if(p1.severity == p2.severity){
                // tie breaking logic
                return p1.arrivalTime > p2.arrivalTime;
            }
            return p1.severity > p2.severity;
        }
};

using ERQueue = priority_queue<Patient, vector<Patient>, compareBySeverity>;
ERQueue buildTriageQueue(vector<Patient> input){
    ERQueue erq;
    for(auto e : input){
        erq.push(e);
    }
    return erq;
}
string peekNext(ERQueue& erq){
    if(erq.empty()) return "";
    return erq.top().name;
}

Patient treatNext(ERQueue & erq){
    Patient result = erq.top();
    erq.pop();
    return result;
}

int main() {
    ERQueue pq = buildTriageQueue(waiting_room);

    cout << "=== Who is next? ===" << endl;
    cout << peekNext(pq) << endl;      //  Bob    (top!)

    cout << "\n=== Treat next ===" << endl;
    Patient p = treatNext(pq);  
    cout << p.name << " (severity " << p.severity << ")" << endl;  // Bob (1)
    cout << peekNext(pq) << endl;        // Eve   

    // cout << "\n=== Full treatment order ===" << endl;
    // ERQueue pq2 = buildTriageQueue(waiting_room);
    // for (const auto& name : treatmentOrder(pq2))
    //     cout << name << " ";
    // cout << endl;                          

    // cout << "\n=== Any critical patients? ===" << endl;
    // ERQueue pq3 = buildTriageQueue(waiting_room);
    // cout << boolalpha << hasCritical(pq3) << endl;  
    // treatNext(pq3);
    // treatNext(pq3);
    // cout << hasCritical(pq3) << endl;              

    return 0;
}
