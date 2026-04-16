#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        if (words[startIndex] == target)
        {
            return 0;
        }

        int size = words.size();
        int turn = ceil((double)(size - 1) / 2);

        for (int i = 1; i <= turn; i++)
        {
            string left = words[(startIndex - i + size) % size];
            string right = words[(startIndex + i) % size];

            if (left == target || right == target)
            {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> words = {"lwgdugypkmsvxwhwbrccrbtemvudwhctnaaonednsbodptendi", "lumylagwxpmmivpujfawgvdbtxpluwekdpeakrqelpvrflnsnr", "lngqwiijizfzzhlvvszaownnachqunlktsnhgsjeluvcpmavuj", "nabbqiyarxmzleesxrfaynypfxonyhvwhebfjsxyinepggxnns", "oiqghjtvrhpgvsjlzmrwbwpmomqqliqytdzawhkwematskflgf", "dtiwjpdgcsmhaiwxrgligxlibfmvclobjjhljrqlvpuiufskix", "svqgvooghuqszkrmcrayqclotygdqnxfetdrfrfvbypgiizzdk", "qzrmfzdiodkdbhwifsinmamljlztwqtaoivufkcyeydsvpmdzw", "ihaekjyxvnmhvtanysybyqvrtmffpkgmnxisgmmhkhbtonlwgo", "ucrvwdlifpckbimcvevgsniepuewjqpakwnxksumgvrnmhmtuk", "lngqwiijizfzzhlvvszaownnachqunlktsnhgsjeluvcpmavuj", "lngqwiijizfzzhlvvszaownnachqunlktsnhgsjeluvcpmavuj", "vdtvcclyyraevotgikgojlbefpfmlzypychxehnglgettackoz", "qxspwpzxfxyxalrjuliwtbyllamkifbknnhzyfeabavwvvdkzk", "vdtvcclyyraevotgikgojlbefpfmlzypychxehnglgettackoz", "ucrvwdlifpckbimcvevgsniepuewjqpakwnxksumgvrnmhmtuk", "dtiwjpdgcsmhaiwxrgligxlibfmvclobjjhljrqlvpuiufskix", "vtbfahotrkxwcfwzlijfoqdkrvdmavpllbcfvibrqeuntsmrcs", "mfhqksxfeeltpiupaijavavbpphjxyuzqlqehirxnmviiaqnfv", "oowbnwbktlmsawtbilyvksqkbuohhjxqbepxgklkrwpjzcvipe", "mpnnvwuqbczvmrwhzvsmtuumwjczqehuumjvfbpgoxlurjbckq", "byaschxhjcgnnodazzpisqriyszffaqqiwljbuigdvzzobrlmc", "dmctcimgeztojrvqwyygmnzfwtsrmmbgednmytsludnrpjjjvk", "qxspwpzxfxyxalrjuliwtbyllamkifbknnhzyfeabavwvvdkzk", "cawzflwjjopbemxqazpsrsrlxljwqlvzpvjbjarqeqgythrsou", "ydqjqvalipkkrcbdprgjjangclswdjpaajiwhxeupidxirlith", "lwgdugypkmsvxwhwbrccrbtemvudwhctnaaonednsbodptendi", "ejtkmbyqtwrlhwynnqggpjaaaydjqnczhtyphfgugpbardzlvj", "cawzflwjjopbemxqazpsrsrlxljwqlvzpvjbjarqeqgythrsou", "oowbnwbktlmsawtbilyvksqkbuohhjxqbepxgklkrwpjzcvipe", "khhwlijglujhgimvfvuwgggigppichzscdtsiklalgqeqsencq", "khhwlijglujhgimvfvuwgggigppichzscdtsiklalgqeqsencq", "lngqwiijizfzzhlvvszaownnachqunlktsnhgsjeluvcpmavuj", "frdsoraagsllmgtatzybegxotrtgsuwfzpzxkpegggvpodnhrr", "ynuartuisymsqxxdqwndonpqhczqpuekwbayfidfisjpriqogx", "shmpixycafoqskoegqfvsrvboiegqwlbrkiuoeetncdxqlqsov", "oiqghjtvrhpgvsjlzmrwbwpmomqqliqytdzawhkwematskflgf", "xjtatoefvpwwgsvmepltadmzngxtnahqypfxgjppbqsmqnjvxm", "vtbfahotrkxwcfwzlijfoqdkrvdmavpllbcfvibrqeuntsmrcs", "dmctcimgeztojrvqwyygmnzfwtsrmmbgednmytsludnrpjjjvk", "dsohnrdxdqrbwdjhqpphwvlzfyizqyoedckthdlhmkxjxewubc", "qriythowwswwwucgwmezpqqneatemdxfqzpeytlozzojguywby", "lyhmqyjnztwzqotqkpmvpueyzjfroousgkkerqvmwjnjtmlkuf", "qzrmfzdiodkdbhwifsinmamljlztwqtaoivufkcyeydsvpmdzw", "qzrmfzdiodkdbhwifsinmamljlztwqtaoivufkcyeydsvpmdzw", "gxrtwoayoosijaddrlbvxqsvbbvaziqemcpxgljlnexvjnnakk", "mjftbskulmuztejkopyftjsdeoyuvhvqragbkqlfhgqqkafvau", "mjftbskulmuztejkopyftjsdeoyuvhvqragbkqlfhgqqkafvau", "qzrmfzdiodkdbhwifsinmamljlztwqtaoivufkcyeydsvpmdzw", "qxspwpzxfxyxalrjuliwtbyllamkifbknnhzyfeabavwvvdkzk"};
    string target = "ydqjqvalipkkrcbdprgjjangclswdjpaajiwhxeupidxirlith";
    int startIndex = 0;

    int answer = solution.closestTarget(words, target, startIndex);
    cout << answer << endl;

    return 0;
}
