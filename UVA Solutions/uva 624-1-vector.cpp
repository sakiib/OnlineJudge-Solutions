#include <cstdio>
#include <vector>
using namespace std;

int track[21];
int N, T; // T is number of tracks
vector<int> Container; // kon kon track nibo
vector<int> Ans;
int Maxsum;
void combination(int pos, int sum);

int main()
{
    while (scanf("%d %d", &N, &T) != EOF) {
        for (int i = 0; i < T; ++i)
            scanf("%d", &track[i]);
        Container.clear();

        Maxsum = 0;
        combination(0, 0);

        int sum = 0;
        for (int n : Ans) {
            printf("%d ", n);
            sum += n;
        }
        printf("sum:%d\n", sum);
    }
}
void combination(int pos, int sum)
{
    if (sum > Maxsum) {
        Ans = Container;
        Maxsum = sum;
    }

    for (int i = pos; i < T; ++i) {
        if (track[i] + sum <= N) {
            sum += track[i];
            Container.push_back(track[i]);

            combination(i + 1, sum);

            sum -= track[i];
            Container.pop_back();
        }
    }
}
