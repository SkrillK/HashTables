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

unordered_map<int, string> hashTableFill()
{
    int numContainers;

    cout << "Number of containers: ";
    cin >> numContainers;

    cout << "\n--- Alg. process ------------------\n";
    cout << "    Word\tCodeSum\tContIndex\n";

    vector<string> words = lineRead();
    unordered_map<int, string> containers;

    for (string word : words)
    {
        int sum = 0;

        for (char c : word)
            sum += int(c);

        int containerNum = sum % numContainers;


        if (!containers[containerNum].empty())
        {
            bool flag = true;

            for (int i = 0; i <= containers.size(); i++)
                if (containers[i].empty())
                {
                    containers[i] = word;
                    cout << "    " << word << " \t" << sum << "\t" << containerNum << " -> " << i << "\n";
                    flag = false;
                    break;
                }
        }
        else 
        {
            containers[containerNum] = word;
            cout << "    " << word << " \t" << sum << "\t" << containerNum << "\n";
        }
    }

    cout << "\n= Result ==========================\n";

    return containers;
}

int main()
{
    unordered_map<int, string> containers = hashTableFill();

    for (int i = 0; i < containers.size(); i++)
    {
        cout << "  C" << i << ":\t";

        if (containers[i].empty())
            cout << "null";
        else
            cout << containers[i] << "\t";

        cout << endl;
    }

    return 0;
}
