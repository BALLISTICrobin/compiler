#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

struct HashReport
{
    string name;
    int collisions;
    double ratio;
};

HashReport parseOutput(const string &filename, const string &hashName)
{
    ifstream infile(filename.c_str());
    string line;
    int collisions = 0;
    double ratio = 0.0;

    while (getline(infile, line))
    {
        if (line.find("Total collisions:") != string::npos)
        {
            size_t pos = line.find(":");
            collisions = atoi(line.substr(pos + 1).c_str());
        }
        else if (line.find("Collision ratio:") != string::npos)
        {
            size_t pos = line.find(":");
            ratio = atof(line.substr(pos + 1).c_str());
        }
    }

    infile.close();
    HashReport report;
    report.name = hashName;
    report.collisions = collisions;
    report.ratio = ratio;
    return report;
}

int main()
{
    const int MAX_HASHES = 3;
    string hashFunctions[MAX_HASHES] = {"sdbm", "djb2", "fnv"};
    HashReport reports[MAX_HASHES];
    int reportCount = 0;

    for (int i = 0; i < MAX_HASHES; i++)
    {
        string hash = hashFunctions[i];
        string outputFile = "./textFolder/temp_" + hash + ".txt";
        string command = "./main ./textFolder/sample_input.txt " + outputFile + " " + hash;
        cout << "Running: " << command << endl;
        int result = system(command.c_str());

        if (result != 0)
        {
            cerr << "Execution failed for hash function: " << hash << endl;
            continue;
        }

        reports[reportCount++] = parseOutput("./textFolder/temp.txt", hash);
    }

    ofstream reportFile("./textFolder/report.txt");

    // Set fixed width for each column
    reportFile << left << setw(20) << "Hash Function"
               << setw(20) << "Total Collisions"
               << setw(20) << "Collision Ratio" << "\n";

    for (int i = 0; i < reportCount; i++)
    {
        reportFile << left << setw(20) << reports[i].name
                   << setw(20) << reports[i].collisions
                   << setw(20) << reports[i].ratio << "\n";
    }

    reportFile.close();

    return 0;
}
