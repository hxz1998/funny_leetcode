/**
 * Created by Xiaozhong on 2021/11/7.
 * Copyright (c) 2021/11/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class UnionSet {
    unordered_map<string, string> parents;
    unordered_map<string, int> sizes;

public:
    void put(string &str, int size) {
        sizes[str] = size;
        parents[str] = str;
    }

    void put(string &&str, int size) {
        sizes[str] = size;
        parents[str] = str;
    }

    void merge(string &lhs, string &rhs) {
        lhs = find(lhs);
        rhs = find(rhs);
        if (lhs < rhs) {
            parents[rhs] = lhs;
            sizes[lhs] += sizes[rhs];
        } else if (rhs < lhs) {
            parents[lhs] = rhs;
            sizes[rhs] += sizes[lhs];
        }
    }

    bool exist(const string &node) {
        return parents.find(node) != parents.end();
    }

    int sizeOf(const string &node) {
        return sizes[node];
    }

    string find(string &node) {
        if (parents[node] == node) return node;
        return find(parents[node]);
    }
};

class Solution {
public:
    vector<string> trulyMostPopular(vector<string> &names, vector<string> &synonyms) {
        UnionSet unionSet;
        vector<string> allNames;
        for (string &name: names) {
            size_t start = name.find("(");
            size_t end = name.find(")");
            unionSet.put(name.substr(0, start),
                         stoi(name.substr(start + 1, end - start - 1)));
            allNames.emplace_back(name.substr(0, start));
        }
        for (string &synonym: synonyms) {
            int idx = synonym.find(",");
            int end = synonym.find(")");
            string lhs = synonym.substr(1, idx - 1);
            string rhs = synonym.substr(idx + 1, end - idx - 1);
            if (!unionSet.exist(lhs)) unionSet.put(lhs, 0);
            if (!unionSet.exist(rhs)) unionSet.put(rhs, 0);
            unionSet.merge(lhs, rhs);
        }
        vector<string> ret;
        for (string &name: allNames) {
            if (unionSet.find(name) == name)
                ret.emplace_back(name + "(" + to_string(unionSet.sizeOf(name)) + ")");
        }
        return ret;
    }
};

ostream &operator<<(ostream &os, vector<string> &data) {
    for (string &item: data) os << item << " ";
    return os;
}

int main() {
    string s[3] = {"c", "a", "b"};
    sort(s, s + 3);
    for (string item: s) cout << item << " ";
    string name = "abcdefg";
    cout << name.substr(0, 3) << endl;
    vector<string> names = {"Fcclu(70)", "Ommjh(63)", "Dnsay(60)", "Qbmk(45)", "Unsb(26)", "Gauuk(75)", "Wzyyim(34)",
                            "Bnea(55)", "Kri(71)", "Qnaakk(76)", "Gnplfi(68)", "Hfp(97)", "Qoi(70)", "Ijveol(46)",
                            "Iidh(64)", "Qiy(26)", "Mcnef(59)", "Hvueqc(91)", "Obcbxb(54)", "Dhe(79)", "Jfq(26)",
                            "Uwjsu(41)", "Wfmspz(39)", "Ebov(96)", "Ofl(72)", "Uvkdpn(71)", "Avcp(41)", "Msyr(9)",
                            "Pgfpma(95)", "Vbp(89)", "Koaak(53)", "Qyqifg(85)", "Dwayf(97)", "Oltadg(95)", "Mwwvj(70)",
                            "Uxf(74)", "Qvjp(6)", "Grqrg(81)", "Naf(3)", "Xjjol(62)", "Ibink(32)", "Qxabri(41)",
                            "Ucqh(51)", "Mtz(72)", "Aeax(82)", "Kxutz(5)", "Qweye(15)", "Ard(82)", "Chycnm(4)",
                            "Hcvcgc(97)", "Knpuq(61)", "Yeekgc(11)", "Ntfr(70)", "Lucf(62)", "Uhsg(23)", "Csh(39)",
                            "Txixz(87)", "Kgabb(80)", "Weusps(79)", "Nuq(61)", "Drzsnw(87)", "Xxmsn(98)", "Onnev(77)",
                            "Owh(64)", "Fpaf(46)", "Hvia(6)", "Kufa(95)", "Chhmx(66)", "Avmzs(39)", "Okwuq(96)",
                            "Hrschk(30)", "Ffwni(67)", "Wpagta(25)", "Npilye(14)", "Axwtno(57)", "Qxkjt(31)",
                            "Dwifi(51)", "Kasgmw(95)", "Vgxj(11)", "Nsgbth(26)", "Nzaz(51)", "Owk(87)", "Yjc(94)",
                            "Hljt(21)", "Jvqg(47)", "Alrksy(69)", "Tlv(95)", "Acohsf(86)", "Qejo(60)", "Gbclj(20)",
                            "Nekuam(17)", "Meutux(64)", "Tuvzkd(85)", "Fvkhz(98)", "Rngl(12)", "Gbkq(77)", "Uzgx(65)",
                            "Ghc(15)", "Qsc(48)", "Siv(47)"};
    vector<string> synonyms = {"(Gnplfi,Qxabri)", "(Uzgx,Siv)", "(Bnea,Lucf)", "(Qnaakk,Msyr)", "(Grqrg,Gbclj)",
                               "(Uhsg,Qejo)", "(Csh,Wpagta)", "(Xjjol,Lucf)", "(Qoi,Obcbxb)", "(Npilye,Vgxj)",
                               "(Aeax,Ghc)", "(Txixz,Ffwni)", "(Qweye,Qsc)", "(Kri,Tuvzkd)", "(Ommjh,Vbp)",
                               "(Pgfpma,Xxmsn)", "(Uhsg,Csh)", "(Qvjp,Kxutz)", "(Qxkjt,Tlv)", "(Wfmspz,Owk)",
                               "(Dwayf,Chycnm)", "(Iidh,Qvjp)", "(Dnsay,Rngl)", "(Qweye,Tlv)", "(Wzyyim,Kxutz)",
                               "(Hvueqc,Qejo)", "(Tlv,Ghc)", "(Hvia,Fvkhz)", "(Msyr,Owk)", "(Hrschk,Hljt)",
                               "(Owh,Gbclj)", "(Dwifi,Uzgx)", "(Iidh,Fpaf)", "(Iidh,Meutux)", "(Txixz,Ghc)",
                               "(Gbclj,Qsc)", "(Kgabb,Tuvzkd)", "(Uwjsu,Grqrg)", "(Vbp,Dwayf)", "(Xxmsn,Chhmx)",
                               "(Uxf,Uzgx)"};
    Solution solution;
    vector<string> ret = solution.trulyMostPopular(names, synonyms);
    cout << ret << endl;
}