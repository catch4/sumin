# pro #17677 뉴스클러스터링
def solution(str1, str2):
    d = {}
    str1, str2 = str1.lower(), str2.lower()

    l1 = [(str1[i]+str1[i+1])
          for i in range(len(str1)-1) if (str1[i]+str1[i+1]).isalpha()]
    l2 = [(str2[i]+str2[i+1])
          for i in range(len(str2)-1) if (str2[i]+str2[i+1]).isalpha()]

    for flag in [(0, 1, l1), (1, 0, l2)]:
        flag1, flag2, l = flag
        for i in l:
            if i not in d:
                d[i] = (0, 0)
            s1, s2 = d[i]
            d[i] = (s1 + flag1, s2 + flag2)

    kyo, hap = 0, 0
    for n1, n2 in d.values():
        kyo += min(n1, n2)
        hap += max(n1, n2)

    if hap == 0:
        return 65536
    return int(kyo/hap*65536)


if __name__ == "__main__":
    print(solution("abc", "abc"))
