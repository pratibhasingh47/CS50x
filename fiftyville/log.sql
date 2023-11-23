-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street';

SELECT * FROM interviews
WHERE transcript LIKE '%bakery%';

SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

SELECT p.name,bsl.activity,bsl.license_plate,bsl.year,bsl.month,bsl.day,bsl.hour,bsl.minute
FROM bakery_security_logs bsl
JOIN people p ON p.license_plate = bsl.license_plate
WHERE bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28  AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25;

SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND year = 2021 AND month = 7 AND day = 28;

SELECT a.* , p.name
FROM atm_transactions a
JOIN bank_accounts b ON a.account_number = b.account_number
JOIN people p ON b.person_id = p.id
where a.atm_location = 'Leggett Street' and a.year = 2021 and a.month = 7 and a.day = 28 and a.transaction_type = 'withdraw';

SELECT *
FROM phone_calls
where year = 2021 and month = 7 and day = 28 and duration < 60;

select p.name,pc.caller,pc.receiver,pc.year,pc.month,pc.day,pc.duration
from phone_calls pc
join people p on pc.caller = p.phone_number
where pc.year =2021 and pc.month = 7 and pc.day = 28 and pc.duration<60;

select * from airports;

select f.* ,origin.full_name as origin_airport, destination.full_name as destination_airport
from flights f
join airports origin on f.origin_airport_id = origin.id
join airports destination on f.destination_airport_id = destination.id
where origin.id  8 and f.year = 2021 and f.month = 7 and f.day =29
order by f.hour,f.minute;

select p.name
from bakery_security_logs bsl
join people p on p.license_plate = bsl.license_plate
join bank_account ba on ba.person_id =p.id
join atm_transactions at on at.account_number = ba.account_number
join phone_calls pc on pc.caller =p.phone_number
where bsl.year = 2021 and bsl.month = 7 and bsl.day=28 and bsl.hour =10 and bsl.minute between 15 and 25
and art.atm_location = 'Leggett Street' and at.year =2021 and at.month =7 and at.day = 28 and at.transaction_type ='withdraw'
and pc.year =2021 and pc.month=7 and pc.day =28 and pc.duration<60;

select p.name
from people p
join passengers ps on p.passport_number = ps.passport_number
where ps.flight_id = 36
and p.name in ('Bruce','Diana');

select p2.name as receiver
from phone_calls pc
join people p1 on pc.caller = p1.phone_number
join people p1 on pc.receiver = p1.phone_number
where p1.name = 'Bruce' and pc.year = 2021  and pc.month = 7 and pc.day = 28 and pc.duration< 60;