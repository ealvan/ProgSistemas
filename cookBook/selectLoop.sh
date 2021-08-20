#!/bin/bash
select DRINK in tea cofee water juice appe all none
do
   case $DRINK in
      tea) 
         echo "Go to canteen"
         ;;
      juice)
         echo "Available at home"
      ;;
      none) 
         break 
      ;;
      *) echo "ERROR: Invalid selection" 
      ;;
   esac
done