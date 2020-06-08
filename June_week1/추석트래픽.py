def solution(lines):
    times, working, answer = [], [], 0

    for line in lines:
        _, time, duration = line.split(' ')
        hour, minute, sec = map(float, time.split(':'))
        d = float(duration[:-1])
        times.append((hour*60*60 + minute*60 + sec - d + 0.001, d))
    times = sorted(times, key=lambda x: x[0])

    for time, _ in times:
        for t, d in working:
            if round(t + d - 0.001, 3) + 1 - 0.001 < time:
                working.remove((t, d))
        working.append((time, _))
        answer = max(answer, len(working))

    return answer
