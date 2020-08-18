# pro 12981 영어끝말잇기
import math


def solution(n, words):
    past = []
    words = [words[0][0]] + words
    for i in range(1, len(words)):
        if words[i] in past or words[i][0] != words[i-1][-1]:
            return [n if (i % n == 0) else i % n, math.ceil(i/n)]
        past.append(words[i])
    return [0, 0]
