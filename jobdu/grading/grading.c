
/* thousands of Graduate Entrance Exams is a hard work.
It is even harder to design a process to make the results as fair as possible.
One way is to assign each exam problem to 3 independent experts.
If they do not agree to each other, a judge is invited to make the final decision.

Now you are asked to write a program to help this process.
    For each problem, there is a full-mark P and a tolerance T(<P) given. The grading rules are:
	    • A problem will first be assigned to 2 experts, to obtain G1 and G2.
		        If the difference is within the tolerance, that is, if |G1 - G2| ≤ T,
				        this problem's grade will be the average of G1 and G2.
						    • If the difference exceeds T, the 3rd expert will give G3.
							    • If G3 is within the tolerance with either G1 or G2, but NOT both,
								        then this problem's grade will be the average of G3 and the closest grade.
										    • If G3 is within the tolerance with both G1 and G2, then this problem's grade will be the maximum of the three grades.
											    • If G3 is within the tolerance with neither G1 nor G2, a judge will give the final grade GJ.
												*/

#include <stdio.h>
#include <stdlib.h>
												static double grading(int p, int t, int g1, int g2, int g3, int gj)
{
	    double interval12, interval13, interval23;
		    double grade;
			    interval12 = g1 > g2? g1-g2: g2-g1;

				    if(interval12 <= t)
						        return (double)(g1+g2)/2;

					    interval13 = g1 > g3? g1-g3: g3-g1;
						    interval23 = g3 > g2? g3-g2: g2-g3;

							    if(interval13 > t && interval23 > t){
									        return gj;
											    }

								    if(interval13 <= t && interval23 <= t){
										        grade = (g1 > g2)? (g1 > g3? g1:g3):(g2>g3? g2:g3);
												        return grade;
														    }

									    grade = interval23 > interval13? (double)(g1+g3)/2:(double)(g2+g3)/2;

										    return grade;
}
int main()
{
	    int p, g1, g2, g3, gj, t;

		    double grade;
			    while(scanf("%d%d%d%d%d%d", &p, &t, &g1, &g2, &g3, &gj) != EOF){
					        grade = grading(p, t, g1, g2, g3, gj);
							        printf("%.1f\n", grade);
									    }

				    return 0;
}

