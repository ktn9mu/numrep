# numrep

Exercise 1 : comparing the results of the upward and downward recursion, both upward and downward recursion give nearly the same results.




Exercise 2 : Landau section 7.5

Q: check whether the number of decimal places obtained agrees roughly with the estimates in the text.?
For the forward difference, the smallest relative error observed was about 1e-7 which is close to Landau’s estimate. The central difference reached about 1e-11. The central difference reached about 1e-11, Landau suggests the error should approach machine precision 1e-16 so, the extrapolated method fell short by roughly a factor of 100, likely due to round-off error becoming significant earlier.


Q : Do the slopes agree with our model’s predictions?
Yes. The slopes measured in the truncation-error regime match the theoretical orders:
Forward difference error scales as 𝑂(h)
Central difference error scales as 𝑂(h^2)
Extrapolated (Richardson) difference error scales as 𝑂(h^4)



 Q: See if you can identify regions where algorithmic (series truncation) error dominates at large h and round-off error at small h in your plot?
The plots clearly show two regimes. At large ℎ, truncation error dominates and the error curves follow the expected slopes for each method. At small h, round-off error takes over and the error increases as h decreases. The crossover points are approximately:
Forward difference h ~ 1e-8
Central difference h ~ 1e-5
Extrapolated difference h ~ 1e-3







