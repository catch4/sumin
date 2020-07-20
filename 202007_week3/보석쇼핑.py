# pro # 67258 보석쇼핑
# head, tail로 처음과 끝 지점을 포인팅하고 있음.
# tail 값을 올릴 때마다 gems_dict에도 해당 value 값을 올려줌.
# gems_dict의 길이가 set_len이 되면 모든 보석이 다 포함된 것이기 때문에 gems_dict에서 해당 value 값을 낮춤.(만약 값이 0이 되면 해당 키를 삭제)


def solution(gems):
    set_len = len(set(gems))
    head, tail, length = 0, 0, len(gems)
    gems_dict, answer, min_len = {}, [1, length], 100001

    while tail < length:
        g_head, g_tail = gems[head], gems[tail]
        if len(gems_dict) != set_len:
            if g_tail not in gems_dict:
                gems_dict[g_tail] = 0
            gems_dict[g_tail] += 1
            tail += 1
            continue
        cur_len = tail - head
        if cur_len < min_len:
            answer, min_len = [head+1, tail], cur_len
        gems_dict[g_head] -= 1
        if gems_dict[g_head] == 0:
            del gems_dict[g_head]
        head += 1
    return answer
