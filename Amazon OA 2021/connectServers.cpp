#include<bits/stdc++.h>

using namespace std;

bool comp (vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int findParent (int s, vector<int> p) {
    if (p[s] == s)
        return s;
    
    return findParent(p[s], p);
}

int main () {
    int n;
    cin >> n;

    vector<vector<int>> connections(n);
    for (int i = 0; i < n; i++) {
        char s, d;
        int w;
        cin >> s >> d >> w;

        vector<int> v(3);
        v[0] = s - 'A';
        v[1] = d - 'A';
        v[2] = w;

        connections.push_back(v);
    }

    for (int i = 0; i < n; i++) {
        cout << connections[i][0] << " " << connections[i][1] << " " << connections[i][2] << endl;
    }

    set<char> s;
    for (int i = 0; i < n; i++) {
        connections[i][0];
        connections[i][1];
    }

    int noOfVertices = s.size();

    sort(connections.begin(), connections.end(), comp);

    vector<int> parent(noOfVertices);
    for (int i = 0; i < noOfVertices; i++) {
        parent[i] = i;
    }

    vector<vector<int>> output(noOfVertices - 1);

    int i = 0;
    int count = 0;

    while (count != noOfVertices - 1) {
        int source = connections[i][0];
        int dest = connections[i][1];

        int pOS = findParent(source, parent);
        int pOD = findParent(dest, parent);

        if (pOS != pOD) {
            output.push_back(connections[i]);
            count++;
            parent[pOS] = pOD;
        }

        i++;
    }

    for (int i = 0; i < noOfVertices - 1; i++) {
        cout << char ('A' + output[i][0]) << " " << char ('A' + output[i][1]) << " " << output[i][2] << endl;
    }


    return 0;
}