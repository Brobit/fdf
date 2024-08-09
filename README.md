to do :

- [x] do a function to calculate the isometric projection
- [x] apply the isometric calcul to the point coordonate
- [x] draw lines between points
- [ ] segfault on elem-fract.fdf

in draw_point, make a struct that only contain the 2 vector that going to be draw,
and then , don't wait the end of the loop to draw a line, draw the line just after
the points calculation, and then draw the two points

the error actually is when a point is out of the map, when i reduce the coef,
it keep the wrong value, so i need to an another structure to do the calculation
without modify the initial value, and to calculate only two points and draw the line
allow to do it without a structure allocation
