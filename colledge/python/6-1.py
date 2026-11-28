try:
    ans = 0
    n = input()
    if typeof(n) != int:
        if typeof(n) == float:
            raise ValueError('Error: please enter an integer')
        else:
            raise ValueError('Error: please enter a number')
    if n < 0 or n > 50:
        raise ValueError('Error: number out of range')
    while(1):
        l = 0;r = 50;
        try:
            nn = input()
            if typeof(nn) != int:
                if typeof(nn) == float:
                    raise ValueError('Error: please enter an integer')
                else:
                    raise ValueError('Error: please enter a number')

            if nn < 0 or nn > 50:
                raise ValueError('Error: number out of range')
            if nn < l:
                raise ValueError('You are too low!')
            if nn > r:
                raise ValueError('You are too high!')
            if nn == n:
                print('You got it!')
                break
        except ValueError as e:
            print(e)
        finally:
           ans+=1
except ValueError as e:
    print(e)
finally:
    print('You guessed '+str(ans)+' times.')
