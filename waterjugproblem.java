import java.io.*;
import java.util.*;
public class waterjugproblem
{
	public static int jug1,jug2,pjug1=0,pjug2=0,req,rule=0,sno=0,reqjug;
	public static String action="Initial Condition";
	public static void display(){
		sno=sno+1;
		System.out.println(sno+"\t\t"+pjug1+"\t\t"+pjug2+"\t\t"+rule+"\t"+action);
	}
	public static void FillJug1(){
		pjug1=jug1;
		action="Fill Jug 1";
		rule=1;
		display();
	}
	public static void TransferFromJug1ToJug2(){
		int temp=jug2-pjug2;
		if(pjug1>=temp)
		{
			pjug2=pjug2+temp;
			pjug1=pjug1-temp;
			rule=8;
			action="Transfer From Jug1 to Jug2";
		}
		else
		{
			pjug2=pjug2+pjug1;
			pjug1=0;
			rule=10;
			action="Pour From Jug1 to Jug2";
		}
		display();
	}
	public static void EmptyJug2(){
		pjug2=0;
		action="Empty Jug 2";
		rule=6;
		display();
	}
	public static void FillJug2(){
		pjug2=jug2;
		action="Fill Jug 2";
		rule=2;
		display();
	}
	public static void TransferFromJug2ToJug1(){
		int temp=jug1-pjug1;
		if(pjug2>=temp)
		{
			pjug1=pjug1+temp;
			pjug2=pjug2-temp;
			rule=7;
			action="Transfer From Jug 2 to Jug 1";
		}
		else
		{
			pjug1=pjug1+pjug2;
			pjug2=0;
			rule=9;
			action="Pour from Jug 2 to Jug 1";
		}
		display();
	}
	public static void EmptyJug1(){
		pjug1=0;
		action="Empty Jug 1";
		rule=5;
		display();
	}
	public static int findgcd()
	{
		int p,q,r=1;
		if(jug1>jug2){
			p=jug1;
			q=jug2;
		}
		else{
			p=jug2;
			q=jug1;
		}
		while(r!=0)
		{
			r=p%q;
			if(r==0)
				break;
			q=p;
			p=r;
		}
		return p;
	}
	public static void main(String args[]) throws IOException
	{
		int flag;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Jug 1:- ");
		jug1=Integer.parseInt(br.readLine());
		System.out.print("Jug 2:- ");
		jug2=Integer.parseInt(br.readLine());
		System.out.print("Required:- ");
		req=Integer.parseInt(br.readLine());
		System.out.print("Required Jug:- ");
		reqjug=Integer.parseInt(br.readLine());
		if(req%findgcd()==0)
		{
			System.out.println("Problem Solvable");
			System.out.println("Sr.No\t\tJug1\t\tJug2\t\tRule\tAction");
			display();
			while(true)
			{
				if(jug1<jug2)
				{
					flag=1;
					FillJug1();
					TransferFromJug1ToJug2();
					if(pjug2==jug2)
						EmptyJug2();
				}
				else
				{
					flag=2;
					FillJug2();
					TransferFromJug2ToJug1();
					if(pjug1==jug1)
						EmptyJug1();
				}
				if(pjug1==req || pjug2==req)
				{
					if(flag==1 && reqjug==2)
						TransferFromJug1ToJug2();
					else if(flag==2 &&reqjug==1)
						TransferFromJug2ToJug1();
					break;
				}
			}
		}
		else
			System.out.println("Problem Unsolvable");
	}
}
