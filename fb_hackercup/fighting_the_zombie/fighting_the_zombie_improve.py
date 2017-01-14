import sys

cache = [[-1] * 10001 for d in range(21)]


def getAvailable(x, y, health):
    cnt = 0
    
    if health <= 0 and x == 0 :
        return 1

    if x * y < health or x == 0 :
        return 0

    if cache[x][health] == -1:
        for i in range(1, y+1):
            cnt += getAvailable(x-1, y, health-i)
        cache[x][health] = cnt

    return cache[x][health]
        

def calculate(health, x, y, z):
    max = pow(y, x)
    health -= z

    cnt = getAvailable(x, y, health)

    return float(cnt)/float(max)



if __name__ == "__main__":
    cases = int(sys.stdin.readline().strip())
    
    for i in range(1, cases+1):
        line_split = sys.stdin.readline().strip().split(' ')
        spell_split = sys.stdin.readline().strip().split(' ')

        zombie_health = int(line_split[0])
        
        possibility_top = 0
    
        for spell in spell_split:
            x = None
            y = None
            z = None

            if '-' in spell:
                splited = spell.split('-')
                dice_splited = splited[0].split('d')
                z = int(splited[1]) * -1
                x = int(dice_splited[0])
                y = int(dice_splited[1])
            
            
            elif '+' in spell:
                splited = spell.split('+')
                dice_splited = splited[0].split('d')
                z = int(splited[1])
                x = int(dice_splited[0])
                y = int(dice_splited[1])

            else:
                dice_splited = spell.split('d')
                x = int(dice_splited[0])
                y = int(dice_splited[1])
                z = 0

            possibility = calculate(zombie_health, x, y, z);
            if possibility > possibility_top:
                possibility_top = possibility

            cache = [[-1] * 10001 for d in range(21)]

        print "Case #%d: %.6f" % (i, possibility_top)


