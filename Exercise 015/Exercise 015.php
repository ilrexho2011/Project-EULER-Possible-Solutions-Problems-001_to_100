<?php
/**
 * Problem: Starting in the top left corner of a 2×2 grid,
 * and only being able to move to the right and down, there
 * are exactly 6 routes to the bottom right corner.
 *
 * 1. right, right, down, down
 * 2. right, down, right, down
 * 3. right, down, down, right
 * 4. down, right, right, down
 * 5. down, right, down, right
 * 6. down, down, right, right
 *
 * How many such routes are there through a 20×20 grid?
 *
 * Solution: Initially, I wanted to brute force this with some
 * loops in loops, but the problem is mathematical by its nature.
 */

include "helper.php";

$grid = 20;
$paths = 1;

for ($i=0; $i < $grid; $i++) {
	$paths *= 2 * $grid - $i;
	$paths /= ($i + 1);
}

result(137846528820, $paths);
