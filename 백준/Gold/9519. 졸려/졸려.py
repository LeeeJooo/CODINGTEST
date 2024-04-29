x = int(input())
word = input()
word_len = len(word)
q = []
if word_len%2 : # 홀수 개
    word_before = word
    while True:
        word_new = ''
        for i in range(word_len//2):
            word_new += word_before[i]
            word_new += word_before[word_len-1-i]
        word_new += word_before[word_len//2]
        q.append(word_new)
        if word_new == word : break
        else : word_before = word_new

else :          # 짝수 개
    word_before = word
    while True:
        word_new = ''
        for i in range(word_len // 2):
            word_new += word_before[i]
            word_new += word_before[word_len - 1 - i]
        q.append(word_new)
        if word_new == word:
            break
        else:
            word_before = word_new

print(q[-(x%len(q)+1)])