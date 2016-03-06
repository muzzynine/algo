package main

import "fmt"

var board [20][20]bool
var dropPossible = [][]int{
	{0, 1, 1, 0, 1, 0},
	{0, 1, 1, 0, 0, 1},
	{0, 1, 0, 1, 1, 0},
	{0, 1, 0, 0, 1, 1}}

var height int
var width int

func main(){
	var cases int

	fmt.Scanf("%d", &cases)
	for cases > 0 {
		boardInitialize()
		
		fmt.Scanf("%d", &height)
		fmt.Scanf("%d", &width)

		var solution int = 0
		numberOfWhite := 0
		
		
		for i := 0 ; i < height ; i++ {
			var boardType string
			fmt.Scanf("%s", &boardType)

			for j := 0 ; j < len(boardType) ; j++ {
				if(boardType[j] == '#'){
					board[i][j] = false
				} else {
					numberOfWhite++
					board[i][j] = true
				}
			}
		}
		if numberOfWhite % 3 == 0 {
			solution = cover();
		}
		fmt.Printf("%d\n", solution)		
		cases--
	}
}

func boardPrint(){
	for i := 0 ; i < height ; i++ {
		for j := 0 ; j <width ; j++ {
			fmt.Print(board[i][j])
			fmt.Printf("\t");
		}
		fmt.Println("");
	}
}

func boardInitialize(){
	for i := 0 ; i < 20 ; i++ {
		for j := 0 ; j < 20 ; j++ {
			board[i][j] = false
		}
	}
}



func checkDropPossible(x int, y int, blockType int) bool{
	for i, value := range dropPossible[blockType] {
		if value == 1 {
			computeX := x + (i % 3 - 1)
			computeY := y + (i / 3)

			if computeX*computeY < 0 || board[computeY][computeX] == false {
				return false
			}
		}
	}
	return true
}

func set(x int, y int, blockType int){
	for i, value := range dropPossible[blockType] {
		if value == 1 {
			plusX := i % 3 - 1
			plusY := i / 3

			if board[y+plusY][x+plusX] == false {
				board[y+plusY][x+plusX] = true
			} else {
				board[y+plusY][x+plusX] = false
			}
		}
	}
}

func cover() int{
	y := -1
	x := -1

	for i := 0; i < height ; i++ {
		for j := 0 ; j < width ; j++ {
			if board[i][j] {
				y = i
				x = j
				break
			}
		}
		if y != -1 {
			break
		}
	}

	if y == -1 {
		return 1
	}

	ret := 0;

	for blockType := 0 ; blockType < 4 ; blockType++ {
		if checkDropPossible(x, y, blockType) {
			set(x, y, blockType)
			ret += cover();
			set(x, y, blockType)
		}
	}
	return ret
}

//wrong recursive
func dropBlock(x int, y int, remainBlocks int) int{
	fmt.Println("#dropBlock", x, " ", y);
	
	if remainBlocks == 0 {
		fmt.Println("found!");

		boardPrint()
		
		tmp := 0
		fmt.Scanf("%d", &tmp)

		return 1
	}

	ret := 0

	for i := y ; i < height ; i++ {
		//i == y인 경우는 dropblock에 처음 들어온 경우이다.
		//두 경우를 나눠서 처리하는 이유는 j인덱스의 초기화 값을 정하기 위해서인데,
		//이를 나중에는 정리해야만 한다.
		if i == y {
			for j := x ; j < width ; j++ {
				// 보드의 현재 위치가 true라면 블록으로 덮을 수 있는 상태이기 때문에,
				// 가능한 블록이 있는지 세팅하고, 이를 이용해 덮는다.
				if board[i][j] {
					for blockType := 0 ; blockType < 4 ; blockType++ {
						if checkDropPossible(j, i, blockType){
							fmt.Println("selected ", blockType, "type")
							set(j, i, blockType)
							remainBlocks--
							ret += dropBlock(j, i, remainBlocks)
							fmt.Println("unselected ", blockType, "type")
							set(j, i, blockType)
							remainBlocks++
						}
					}
				}
			}
		} else {
			for j := 0 ; j < width ; j++ {
				if board[i][j] {
					for blockType := 0 ; blockType < 4 ; blockType++ {
						if checkDropPossible(j, i, blockType){
							fmt.Println("selected ", blockType, "type")
							set(j, i, blockType)
							remainBlocks--
							ret += dropBlock(j, i, remainBlocks)
							fmt.Println("unselected ", blockType, "type")
							set(j, i, blockType)
							remainBlocks++
						}

					}
				}
			}
		}
		
	}

	return ret
}
 		
