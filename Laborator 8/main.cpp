#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
#include<utility>
using namespace std;
ifstream fin("phrase.txt");

class compare {

public:
	bool operator()(pair<string, int> p1, pair<string,int> p2) {

		if (p1.second < p2.second) {
			return true;
		}
		else if (p1.second > p2.second)
			return false;
		else return p1.first < p2.first;

	}

};

string phrase;
priority_queue<pair<string, int>,vector<pair<string,int>>,compare> pq;
map<string, int> freq;


int main() {

	getline(fin, phrase);

	string word;

	for (int i = 0; i < phrase.size(); i++) {

		if (phrase[i] == ' ' || phrase[i] == ',' || phrase[i] == '?' || phrase[i] == '!' || phrase[i] == '.' ) {
			if (word.empty() == false) {

				for (int j = 0; j < word.size(); j++) {
					word[j] = tolower(word[j]);
				}
				cout << word << ' ';
				freq[word]++;
				word.clear();
			}
		}
		else {
			word += phrase[i];
		}


	}

	if (word.empty() == false) {

		for (int j = 0; j < word.size(); j++) {
			word[j] = tolower(word[j]);
		}
		cout << word << ' ';
		freq[word]++;
		word.clear();
	}

	map<string, int>::iterator it;

	for (it = freq.begin(); it != freq.end(); it++) {
		pq.push(make_pair(it->first, it->second));
	}

	while (pq.empty() == false) {
		cout << pq.top().first << " => " << pq.top().second << endl;
		pq.pop();
	}

	return 0;
}
