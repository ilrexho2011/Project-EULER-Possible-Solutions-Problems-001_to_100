<?php
$number = bcpow('2','1000');
$length = strlen($number);
$j = 0;

for ($i = 0; $i < $length; $i++)
        {
         $j += $number[$i];
}
echo $j;

?>