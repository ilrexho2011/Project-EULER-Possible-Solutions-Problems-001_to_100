public static int pathSum (int precision, int ROW_MAX, String FILE_NAME){
		//this method returns the largest path sum of a triangle of numbers
		// it is identically used in question18 and quesiton67 so its a method
		// Precision is how many numbers to look ahead before deciding direction
		// row max is how many rows in the text file of numbers
		// filename is the filename.. lol.. remember to add 15 lines of zeros to the end of file
		
		int sum = 0;						// sum of the major path
		int pSum [] = new int [3];			// sum of tested path
		int column = 0;						// current column on the row
		int tCol [] = new int [3];		// the column  were testing
		String lines [] = new String [ROW_MAX+15];// holds the whole triangle
		
		// Fill lines array with data from text file
		try{
			BufferedReader br = new BufferedReader (new FileReader (FILE_NAME));
			while (br.ready()){
				lines[column] = br.readLine();
				column ++;
			}// end while
			br.close();
		}catch(Exception e){Debug("Error:"+e);}
		column = 0;
		
		// go through each row of the triangle
		for (int row = 0; row < ROW_MAX; row++){
			sum += Integer.parseInt (lines[row].substring(column,column+2));
			
			tCol[0] = (byte)column;
			tCol[2] = (byte)column;
			tCol[2] += (byte)2;
			pSum[0] = Integer.parseInt(lines[row+1].substring(tCol[0],tCol[0]+2));
			pSum[2] = Integer.parseInt(lines[row+1].substring(tCol[2],tCol[2]+2));
			
			// decide which path to take by comparing the sums of the next 'precision' numbers						
			for (byte steps = 2; steps <= precision; steps ++){
				// Mod is either digit below to left, or right
				for (byte mod = 0; mod <= 2; mod += (byte)2){
					if (Integer.parseInt(lines[row+steps].substring(tCol[mod],tCol[mod]+2)) > Integer.parseInt(lines[row+steps].substring(tCol[mod]+2,tCol[mod]+4))){
						pSum[mod] += Integer.parseInt(lines[row+steps].substring(tCol[mod],tCol[mod]+2));
						tCol[mod] += 0;
					}else{
						pSum[mod] += Integer.parseInt(lines[row+steps].substring(tCol[mod]+2,tCol[mod]+4));
						tCol[mod] += 2;
					}
				}// end for mod
			}// end for steps
			
			
			// Which one was bigger over the last precision numbers?
			if (row + 1 != ROW_MAX){
				if (pSum[2] > pSum[0]){
					column += 2;
				}else if (pSum[0] > pSum[2]){
					
				}else{ // they are the same, pick bigger starting number
					
					if (Integer.parseInt(lines[row+1].substring(column,column+2)) >= Integer.parseInt(lines[row+1].substring(column+2,column+4))){
						
					}else{
						
						column += 2;
					}
					
				}
				if (row >= ROW_MAX-precision+5){
					precision --;
				}
			}// end if max
		}// end for row
		return sum;
	}// end pathSum