#include <iostream>
#include <vector>
#include <unordered_map>

#include <fstream>
#include <string>
#include <sstream>


using namespace std;

vector<string> lineRead()
{
    ifstream file;

    vector<string> words;

    file.open("words.txt");
    if (file.is_open())
    {
        string word;

        while (getline(file, word, ' '))
            words.push_back(word);
    }

    return words;
}

unordered_map<int, vector<string>> hashTableFill()
{
    int numContainers;

    cout << "Number of containers: ";
    cin >> numContainers;

    cout << "\n--- Alg. process ------------------\n";
    cout << "    Word\tCodeSum\tContIndex\n";

    vector<string> words = lineRead();
    unordered_map<int, vector<string>> containers;

    for (string word : words)
    {
        int sum = 0;

        for (char c : word)
            sum += int(c);

        int containerNum = sum % numContainers;

        cout << "    " << word << " \t" << sum << "\t" << containerNum << "\n";

        containers[containerNum].push_back(word);
    }

    cout << "\n= Result ==========================\n";

    return containers;
}

int main()
{
    unordered_map<int, vector<string>> containers = hashTableFill();

    for (int i = 0; i < containers.size(); i++)
    {
        cout << "  C" << i + 1 << ":\t";

        if (containers[i].empty())
            cout << "null";
        else
        {
            for (string word : containers[i])
                cout << word << "\t";

        }

        cout << endl;
    }

    return 0;
}