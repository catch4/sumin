def solution(files):
    file_splits = []
    for file in files:
        head, number, tail = "", "", ""
        for i in range(len(file)):
            if file[i].isnumeric():
                break
        head = file[:i]
        for j in range(i, len(file)):
            if not file[j].isnumeric():
                break
        if j == len(file)-1:
            number, tail = file[i:], ''
        else:
            number, tail = file[i:j], file[j:]
        file_splits.append((head, number, tail))

    file_splits = sorted(file_splits, key=lambda x: (x[0].lower(), int(x[1])))
    return ["".join(x) for x in file_splits]

