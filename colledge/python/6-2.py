n = int(input())
cnt = 0
score = 0
while n:
    n-=1
    s = input().strip()
    s = s.split(',')
    try:
        if len(s) != 2:
            raise ValueError('Error: invalid data format')
        try:
            s[1] = int(s[1])
        except ValueError:
            raise ValueError('Error: invalid score')
        if s[1] < 0 or s[1] > 100:
            raise ValueError('Error: invalid score')
        print('OK');
        score += s[1]
        cnt+=1
    except ValueError as e:
        print(e)
if cnt == 0:
    print('No valid scores')
else:
    print(f'Average score: {score/cnt:.2f}')
