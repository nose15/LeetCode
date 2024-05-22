**Task 22**
I imagine this as calculating all possible test scenarios for an U-Boot given *n* units of fuel that allows it to go up. It has (n * 2) moves and each time it can go downwards or upwards as long as it comes back up after the mission.
The number of parentheses to match is actually the deepness at which the boat is after its n-th move. The number of parentheses left to write is the potential of an U-Boot to submerge deeper without loosing the ability to come back up.
So when the deepness is 0 then the u-boot can't go any higher, so we only calculate what would happen if it went down again.
When we have no moves downwards, then the uboot can only go up because otherwise it wouldn't be able to go back up.
And when the uboot still has the ability to go downward but is also underwater, then we can either go up or down so we can caluclate both of these routes.
Each time the uboot goes down it has to account for the cost of going back up again so the crew takes care of not going down too many times and counts the moves left to go down (the leftToWrite variable in the code).
