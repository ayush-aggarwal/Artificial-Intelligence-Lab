import java.io.*;
import java.util.*;
public class boggle_game{
	public static String dictionary[];
	public static int dict_size;
	public static void generate_all_words_from_boggle(String boggle[][],Boolean visited[][],int i, int j, String str)
	{
		visited[i][j]=true;
		str=str+boggle[i][j];
		//check word in dictionary
		for(int x=0;x<dict_size;x++)
			if(str.equals(dictionary[x]))
				System.out.println(str);
		for(int m=i-1;m<3 && m<i+2;m++)
			for(int n=j-1;n<3 && n<j+2;n++)
				if(m>=0 && n>=0)
					if(visited[m][n]==false)
						generate_all_words_from_boggle(boggle,visited,m,n,str);
		str=str.substring(0,str.length()-1);
		visited[i][j]=false;					 
	}
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String boggle[][]=new String[3][3];
		Boolean visited[][]=new Boolean[3][3];
		System.out.println("Enter Boggle:-");
		String str="";
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				boggle[i][j]=br.readLine();
		System.out.println("Enter size of dictionary:- ");
		dict_size=Integer.parseInt(br.readLine());
		dictionary=new String[dict_size];
		for(int i=0;i<dict_size;i++)
			dictionary[i]=br.readLine();
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				visited[i][j]=false;
		System.out.println("The strings are:- ");
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				generate_all_words_from_boggle(boggle,visited,i,j,str);
	}
}
				
