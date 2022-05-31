(*1*)
fun is_older(date1: (int*int*int), date2: (int*int*int)) = 
    if #1 date1 < #1 date2
    then true
    else
        if #1 date1 = #1 date2 andalso #2 date1 < #2 date2
        then true
        else
            if #1 date1 = #1 date2 andalso #2 date1 = #2 date2 andalso #3 date1 < #3 date2
            then true
            else false



(*2*)
fun number_in_month(dates: (int*int*int) list, month: int) =
    if null dates
    then 0
    else
        if #2 (hd dates) = month
        then 1+number_in_month(tl dates, month)
        else 0+number_in_month(tl dates, month);


(*3*)
fun number_in_months(dates: (int*int*int) list, months: int list) = 
    if null months
    then 0
    else if null dates
    then 0
        else if #2 (hd dates) = (hd months)
        then 1+number_in_months(tl dates, months)
        else 0+number_in_months(dates, tl months);

(*4*)
fun dates_in_month(dates: (int*int*int) list, month: int)=
    if null dates then []
    else if #2 (hd dates) = month
    then (hd dates)::dates_in_month(tl dates, month)
    else dates_in_month(tl dates, month);

(*5*)
fun dates_in_months(dates: (int*int*int) list, months: int list)=
    if null dates then []
    else if null months then []
    else if 
        let fun is_date_in_month(date : int, month : int list) = 
            if null month
            then false
            else if date = (hd month)
            then true
            else is_date_in_month(date , tl month)
        in
            is_date_in_month(#2 (hd dates),months)
        end

        then (hd dates) :: dates_in_months(tl dates,months)
        else dates_in_months(tl dates,months);

(*6*)
fun get_nth(strings: string list, n: int)=
    if n=1 then hd strings
    else get_nth(tl strings, n-1)

(*7*)
fun date_to_string(date: (int*int*int))=
    get_nth(["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November"], #2 date)^" "^Int.toString(#3 date )^", "^Int.toString(#1 date);

(*8*)
fun number_before_reaching_sum(numbers: int list, sum: int)=
    if null numbers
    then 0
    else
        if (hd numbers) < sum
        then 1 + number_before_reaching_sum(tl numbers, sum - (hd numbers))
        else 0;

(*9*)
fun what_month(day: int)=
    let
        val months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    in
        number_before_reaching_sum(months, day) + 1
    end;

(*10*)
fun range(min: int, max: int) =
  if min <= max
  then min :: range(min + 1, max)
  else [];

fun month_range(day1: int, day2: int)=
    if day1>day2 then []
    else range(
    what_month(day1),
    what_month(day2)
  );

(*11*)
fun oldest_checker(dates: (int*int*int) list, date: (int*int*int))=
    if null dates then date
    else
        if is_older(date, hd dates)
        then oldest_checker(tl dates, date)
        else oldest_checker(tl dates, hd dates);

fun oldest_function(dates: (int*int*int) list)=
    if null dates then NONE
    else SOME(oldest_checker(tl dates, hd dates));



fun task1_test() =
    if is_older((2015, 05, 05),(2017, 05, 05)) <> true
    then raise Fail "Test of task 1 failed."
    else
    print("Test of task 1 passed.");
task1_test();

fun task2_test() =
    if number_in_month([(2003, 05, 05),(2022, 05, 18),(2022, 03, 03)], 05) <> 2
    then raise Fail "Test of task 2failed"
    else
    print("Test of task 2 passed");
task2_test();

fun task3_test() = 
    if number_in_months([(2003, 05, 05), (2022, 05, 18), (2022, 03, 03), (2017, 12, 12)], [5, 3]) <> 3
    then raise Fail "Test of task 3 failed"
    else
    print("Test of task 3 passed");
task3_test();

fun task4_test() = 
    if dates_in_month([(2003, 05, 05), (2022, 05, 18), (2022, 03, 03)], 05) <> [(2003, 05, 05),(2022, 05, 18)]
    then raise Fail "Test of task 4 failed"
    else
    print("Test of task 4 passed");
task4_test();

fun task5_test() = 
    if dates_in_months([(2003, 05, 05), (2022, 05, 18), (2022, 03, 03), (2022, 12, 12)], [03, 05]) <> [(2003, 05, 05), (2022, 05, 18), (2022, 03, 03)]
    then raise Fail "Test of task 5 failed"
    else
    print("Test of task 5 passed");
task5_test();

fun task6_test() = 
    if get_nth(["aaa", "bbb", "ccc", "ddd", "eee"], 4) <> "ddd"
    then raise Fail "Test of task 6 failed"
    else
    print("Test of task 6 passed");
task6_test();

fun task7_test() =
    if date_to_string(2022, 02, 28) <> "February 28, 2022"
    then raise Fail "Test of task 7 failed"
    else
    print("Test of task 7 passed");
task7_test();

fun task8_test() =
    if number_before_reaching_sum([1, 2, 3, 4, 5, 6, 7, 8, 9], 20) <> 5
    then raise Fail "Test of task 8 failed"
    else
    print("Test of task 8 passed");
task8_test();

fun task9_test() =
    if what_month(17) <> 01
    then raise Fail "Test of task 9 failed"
    else
    print("Test of task 9 passed");
task9_test();

fun task10_test() =
    if month_range(12, 120) <> [1, 2, 3, 4]
    then raise Fail "Test of task 10 failed"
    else
    print("Test of task 10 passed");
task10_test();

fun task11_test() =
    if oldest_function([(2020, 05, 05), (2022, 05, 05)]) <> SOME((2020, 05, 05))
    then raise Fail "Test of task 1 failed"
    else
    print("Test of task 11 passed");
task11_test();