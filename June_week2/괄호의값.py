data, stack, answer = list(input()), [], 0
for elem in data:
    if elem == '(' or elem == '[':
        stack.append(elem)
    elif elem == ')' or elem == ']':
        tmp, cur_num, stopped = 0, (2 if elem == ')' else 3), False
        for s in reversed(stack):
            stack.pop()
            if (elem == ')' and s == '(') or (elem == ']' and s == '['):
                stopped = True
                break
            elif type(s) == int:
                tmp += int(s)
        if stopped:
            stack.append(cur_num if tmp == 0 else cur_num*tmp)
        else:
            print(0)
            exit(0)
if '[' in stack or '(' in stack:
    print(0)
else:
    print(sum(stack))
