# Car Dealsership System in C++-

this code enables user to register their ID's with password(including symbols), which then saves the data to a txt file named user.txt
every time the code runs, it will directly take the data from the txt file in the computer for authentication

$${\color{blue}1: Authentication and Menu Display}$$
•	Task: Implementing the login function and displayMenu.
•	Details:
1.	login: Ensure secure access to the system.
2.	displayMenu: Display available options for various tasks.

2: Car Management
•	Task: Adding new cars and modifying car data.
•	Details:
1.	addCar: Generate car ID and save car information.
	generateCarID: Generate unique car IDs.
	saveCarInfo: Save the car details.
2.	modifyCarData: Modify existing car details 

3: Display and Sorting
•	Task: Displaying and sorting car records.
•	Details:
1.	displayAllCars: Display an unsorted list of all car records 
2.	sortCars: Implement sorting by brand, price, and ID 
	sortByBrand: Sort cars by brand.
	sortByPrice: Sort cars by price.
	sortByID: Sort cars by ID.
	sortByBestSellingBrand: Sort best selling cars
 
4: Searching and Tracking
•	Task: Implementing search functionalities and tracking the number of cars sold.
•	Details:
1.	searchCarByID: Implement linear and binary search algorithms 
	linearSearch: Implement linear search.
	binarySearch: Implement binary search.
2.	searchBestSellingBrand: Binary Search
3.	trackNumberOfCarsSold: Track and display the number of cars sold 
4.	removeCarRecord: Implement functionality to remove a car record 
5.	Check stock

5: Billing and Reporting
•	Task: Generating bills, searching bills, and generating reports.
•	Details:
1.	generateBill: Generate purchase order numbers, calculate total prices, and create bills 
	generatePurchaseOrderNumber: Generate unique purchase order numbers.
	calculateTotalPrice: Calculate the total price of the purchase.
2.	searchBills: Implement search functionality for bills by customer ID and bill date (depends on generateBill).
	searchByCustomerID: Implement search by customer ID.
	searchByBillDate: Implement search by bill date.
3.	generateReport: Compile list of purchases within a specified period and sort by price using quicksort (depends on generateBill).
	compileList: Compile the list of purchases.
	quickSortByPrice: Sort the purchases by price.
