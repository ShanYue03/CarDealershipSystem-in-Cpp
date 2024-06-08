                                                                                       # Car Dealsership System in C++-

Code Scenario and background: You are a software developer at a software development company. One of the largest car dealerships has
approached your company, requesting a program to manage their business operations. The purpose of this
system is to streamline tasks related to car brands, customers, billing, and more.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


$${\color{blue}1: Authentication and Menu Display}$$
•	Task: Implementing the login function and displayMenu.
•	Details:
1.	login: Ensure secure access to the system.
2.	displayMenu: Display available options for various tasks.

$${\color{blue}2: Car Management}$$
•	Task: Adding new cars and modifying car data.
•	Details:
1.	addCar: Generate car ID and save car information.
	generateCarID: Generate unique car IDs.
	saveCarInfo: Save the car details.
2.	modifyCarData: Modify existing car details 

$${\color{blue}3: Display and Sorting}$$
•	Task: Displaying and sorting car records.
•	Details:
1.	displayAllCars: Display an unsorted list of all car records 
2.	sortCars: Implement sorting by brand, price, and ID 
	sortByBrand: Sort cars by brand.
	sortByPrice: Sort cars by price.
	sortByID: Sort cars by ID.
	sortByBestSellingBrand: Sort best selling cars
 
$${\color{blue}4: Searching and Tracking}$$
•	Task: Implementing search functionalities and tracking the number of cars sold.
•	Details:
1.	searchCarByID: Implement linear and binary search algorithms 
	linearSearch: Implement linear search.
	binarySearch: Implement binary search.
2.	searchBestSellingBrand: Binary Search
3.	trackNumberOfCarsSold: Track and display the number of cars sold 
4.	removeCarRecord: Implement functionality to remove a car record 
5.	Check stock

$${\color{blue}5: Billing and Reporting}$$
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
