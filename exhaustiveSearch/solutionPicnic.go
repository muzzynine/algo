/* 안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을
 * 갑니다.  원석 선생님은 소풍 때 학생들은 두 명씩 짝을 지어 행동하게
 * 하려고 합니다. 그런데 서로 친구가 아닌 학생들끼리 짝을 지어주면
 * 서로 싸우거나 같이 돌아다니지 않기 떄문에, 항상 서로 친구인
 * 학생들끼리만 짝을 지어야합니다. 각 학생들의 쌍에 대해 이들이 서로
 * 친구인지 여부가 주어질 때, 학생들을 짝 지을 수 있는 방법의 수를
 * 계산하는 프로그램을 작성하세요. 짝이 되는 학생들이 일부만
 * 다르더라도 다른 방법이라고 봅니다. */

package main

import "fmt"

var n int;

func main(){
	var cases int
	var friendPair int
	
	fmt.Scanf("%d", &cases)
	for cases > 0 {
		fmt.Scanf("%d", &n)
		fmt.Scanf("%d", &friendPair)
		
		areFriends := make([][]bool, n)

		for i := 0 ; i < n ; i++ {
			areFriends[i] = make([]bool, n)
		}

		
		for friendPair > 0 {
			var pairA int
			var pairB int
			fmt.Scanf("%d", &pairA)
			fmt.Scanf("%d", &pairB)

			areFriends[pairA][pairB] = true
			areFriends[pairB][pairA] = true
			
			friendPair--
		}
		
		taken := make([]bool, n)
		
		solution := countPairings(taken, areFriends)
		fmt.Printf("%d\n", solution)
		cases--
	}
}

func countPairings(taken []bool, areFriends [][]bool) int{
	firstFree := -1

	for i := 0 ; i < n ; i++ {
		if !taken[i] {
			firstFree = i
			break
		}
	}

	if firstFree == -1 {
		return 1
	}

	ret := 0

	for pairWith := firstFree+1; pairWith < n; pairWith++ {
		if(!taken[pairWith] && areFriends[firstFree][pairWith]){
			taken[firstFree] = true
			taken[pairWith] = true
			ret += countPairings(taken, areFriends)
			taken[firstFree] = false
			taken[pairWith] = false
		}
	}
	return ret;
}

		
	
