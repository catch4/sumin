# BOJ # 5373 큐빙 (solved))
# 시뮬레이션 문제라 하나하나 다 구현하면서 품.
# 처음에 시계방향, 시계반대방향을 각각 따로 구현하느라 시간이 훨씬오래걸리고 디버깅도 너무 힘들었다.

c = {}


def init():
    global c
    c = {
        'U': [['w' for _ in range(3)] for _ in range(3)],
        'D': [['y' for _ in range(3)] for _ in range(3)],
        'F': [['r' for _ in range(3)] for _ in range(3)],
        'B': [['o' for _ in range(3)] for _ in range(3)],
        'L': [['g' for _ in range(3)] for _ in range(3)],
        'R': [['b' for _ in range(3)] for _ in range(3)]
    }


def turn(s, direction):
    k = 1 if direction == '+' else 3
    if s == 'U':
        for _ in range(k):
            b, r, f, l = c['B'][0], c['R'][0], c['F'][0], c['L'][0]
            c['B'][0] = l[:]
            c['R'][0] = b[:]
            c['F'][0] = r[:]
            c['L'][0] = f[:]
    elif s == 'D':
        for _ in range(k):
            f, r, b, l = c['F'][2], c['R'][2], c['B'][2], c['L'][2]
            c['F'][2] = l[:]
            c['R'][2] = f[:]
            c['B'][2] = r[:]
            c['L'][2] = b[:]
    elif s == 'F':
        for _ in range(k):
            u, r, d, l = c['U'][2], [a[0]
                                     for a in c['R']],  c['D'][0],  [a[2] for a in c['L']]
            c['U'][2] = list(reversed(l[:]))
            c['R'][0][0], c['R'][1][0], c['R'][2][0] = u[:]
            c['D'][0] = list(reversed(r[:]))
            c['L'][0][2], c['L'][1][2], c['L'][2][2] = d[:]
    elif s == 'B':
        for _ in range(k):
            u, r, d, l = c['U'][0],  [a[2]
                                      for a in c['R']],  c['D'][2],  [a[0] for a in c['L']]
            c['U'][0] = r[:]
            c['L'][0][0], c['L'][1][0], c['L'][2][0] = list(reversed(u[:]))
            c['D'][2] = l[:]
            c['R'][0][2], c['R'][1][2], c['R'][2][2] = list(reversed(d[:]))

    elif s == 'L':
        for _ in range(k):
            u, f, d, b = [a[0] for a in c['U']],  [a[0] for a in c['F']],  [
                a[0] for a in c['D']], [a[2] for a in c['B']]
            c['D'][0][0], c['D'][1][0], c['D'][2][0] = f[:]
            c['U'][0][0], c['U'][1][0], c['U'][2][0] = list(reversed(b[:]))
            c['F'][0][0], c['F'][1][0], c['F'][2][0] = u[:]
            c['B'][0][2], c['B'][1][2], c['B'][2][2] = list(reversed(d[:]))
    elif s == 'R':
        for _ in range(k):
            u, b, d, f = [a[2] for a in c['U']],  [a[0] for a in c['B']], [
                a[2] for a in c['D']],  [a[2] for a in c['F']]
            c['U'][0][2], c['U'][1][2], c['U'][2][2] = f[:]
            c['B'][0][0], c['B'][1][0], c['B'][2][0] = list(reversed(u[:]))
            c['D'][0][2], c['D'][1][2], c['D'][2][2] = list(reversed(b[:]))
            c['F'][0][2], c['F'][1][2], c['F'][2][2] = d[:]


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        init()
        n = int(input())
        cmds = input().split()
        for cmd in cmds:
            s, d = cmd[0], cmd[1]
            # 해당 면 회전
            if d == '+':
                c[s] = [list(reversed([line[i] for line in c[s]]))
                        for i in range(3)]
            else:
                c[s] = list(reversed([[line[i] for line in c[s]]
                                      for i in range(3)]))
            # 주변 선 회전
            turn(s, d)
        for i in range(3):
            print("".join(c['U'][i]))
