# PRO # 17676 추석 트래픽
# 문제를 꼼꼼하게 읽고 이해했다면 어렵지는 않았던 문제(꼼꼼하게 읽는게 어려움 😂)


def solution(lines):
    times, stk, ans = [], [], 0
    for line in lines:
        _, s, t = line.split()
        h, m, sec = s.split(':')
        s = float(h)*60*60*1000 + float(m)*60 * 1000 + float(sec)*1000
        t = float(t[:-1])*1000
        times.append((s-t+1, s))
    times = sorted(times, key=lambda x: x[0])
    for (start, end) in times:
        for st in stk:
            if st[1] + 999 < start:
                stk.remove(st)
        stk.append((start, end))
        ans = max(ans, len(stk))
    return ans
