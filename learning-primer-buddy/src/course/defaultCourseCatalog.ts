import { CourseCatalog } from './types';

/**
 * Provides sample course catalog data for testing and development purposes.
 * Follows the new hierarchical model: CourseCatalog -> Course -> CourseExercise -> Folder/File
 */
export const defaultCourseCatalog: CourseCatalog = {
	version: "1.0",
	type: "catalog",
	courses: [
		{
			id: "cpp-primer-5th",
			title: "C++ Primer 5th Edition",
			description: "Learning path for C++ Primer 5th Edition",
			level: "Intermediate",
			estimatedHours: 40,
			hasProtectedContent: true,
			isFree: false,
			version: "5th Edition",
			type: "course",
			exercises: [
				{
					id: "getting_started",
					title: "1. Getting Started",
					description: "Introduction to C++ programming",
					type: "exercise",
					folders: [
						{
							id: "examples",
							name: "examples",
							path: "/1_getting_started/examples",
							type: "folder",
							folders: [],
							files: [
								{
									id: "hello_cpp",
									name: "hello.cpp",
									path: "/1_getting_started/examples/hello.cpp",
									extension: "cpp",
									type: "file"
								},
								{
									id: "variables_cpp",
									name: "variables.cpp",
									path: "/1_getting_started/examples/variables.cpp",
									extension: "cpp",
									type: "file"
								}
							]
						}
					],
					files: [
						{
							id: "intro_cpp",
							name: "introduction.md",
							path: "/1_getting_started/introduction.md",
							extension: "md",
							type: "file"
						},
						{
							id: "hello_world",
							name: "hello_world.cpp",
							path: "/1_getting_started/hello_world.cpp",
							extension: "cpp",
							type: "file"
						},
						{
							id: "compiling_guide",
							name: "compiling_guide.md",
							path: "/1_getting_started/compiling_guide.md",
							extension: "md",
							type: "file"
						}
					]
				},
				{
					id: "variables_basic_types",
					title: "2. Variables and Basic Types",
					description: "Understanding variables and basic data types in C++",
					type: "exercise",
					folders: [
						{
							id: "exercises",
							name: "exercises",
							path: "/2_variables/exercises",
							type: "folder",
							folders: [
								{
									id: "solutions",
									name: "solutions",
									path: "/2_variables/exercises/solutions",
									type: "folder",
									folders: [],
									files: [
										{
											id: "solution1",
											name: "solution1.cpp",
											path: "/2_variables/exercises/solutions/solution1.cpp",
											extension: "cpp",
											type: "file"
										},
										{
											id: "solution2",
											name: "solution2.cpp",
											path: "/2_variables/exercises/solutions/solution2.cpp",
											extension: "cpp",
											type: "file"
										}
									]
								}
							],
							files: [
								{
									id: "exercise1",
									name: "exercise1.cpp",
									path: "/2_variables/exercises/exercise1.cpp",
									extension: "cpp",
									type: "file"
								},
								{
									id: "exercise2",
									name: "exercise2.cpp",
									path: "/2_variables/exercises/exercise2.cpp",
									extension: "cpp",
									type: "file"
								}
							]
						}
					],
					files: [
						{
							id: "variables_overview",
							name: "variables_overview.md",
							path: "/2_variables/variables_overview.md",
							extension: "md",
							type: "file"
						},
						{
							id: "data_types",
							name: "data_types.cpp",
							path: "/2_variables/data_types.cpp",
							extension: "cpp",
							type: "file"
						},
						{
							id: "type_conversion",
							name: "type_conversion.cpp",
							path: "/2_variables/type_conversion.cpp",
							extension: "cpp",
							type: "file"
						}
					]
				},
				{
					id: "strings_vectors_arrays",
					title: "3. Strings, Vectors, and Arrays",
					description: "Working with strings, vectors, and arrays in C++",
					type: "exercise",
					folders: [
						{
							id: "projects",
							name: "projects",
							path: "/3_strings/projects",
							type: "folder",
							folders: [
								{
									id: "string_analyzer",
									name: "string_analyzer",
									path: "/3_strings/projects/string_analyzer",
									type: "folder",
									folders: [],
									files: [
										{
											id: "main",
											name: "main.cpp",
											path: "/3_strings/projects/string_analyzer/main.cpp",
											extension: "cpp",
											type: "file"
										},
										{
											id: "string_utils_cpp",
											name: "string_utils.cpp",
											path: "/3_strings/projects/string_analyzer/string_utils.cpp",
											extension: "cpp",
											type: "file"
										},
										{
											id: "string_utils_h",
											name: "string_utils.h",
											path: "/3_strings/projects/string_analyzer/string_utils.h",
											extension: "h",
											type: "file"
										},
										{
											id: "makefile",
											name: "Makefile",
											path: "/3_strings/projects/string_analyzer/Makefile",
											extension: "makefile",
											type: "file"
										}
									]
								}
							],
							files: []
						}
					],
					files: [
						{
							id: "strings_basics",
							name: "strings_basics.md",
							path: "/3_strings/strings_basics.md",
							extension: "md",
							type: "file"
						},
						{
							id: "string_operations",
							name: "string_operations.cpp",
							path: "/3_strings/string_operations.cpp",
							extension: "cpp",
							type: "file"
						},
						{
							id: "vectors_guide",
							name: "vectors_guide.md",
							path: "/3_strings/vectors_guide.md",
							extension: "md",
							type: "file"
						},
						{
							id: "arrays_basics",
							name: "arrays_basics.cpp",
							path: "/3_strings/arrays_basics.cpp",
							extension: "cpp",
							type: "file"
						}
					]
				}
			]
		},
		{
			id: "python-3rd-edition",
			title: "Python 3rd Edition",
			description: "Python programming from beginner to advanced",
			level: "Beginner",
			estimatedHours: 35,
			hasProtectedContent: false,
			isFree: true,
			version: "3rd Edition",
			type: "course",
			exercises: [
				{
					id: "python-intro",
					title: "Python Introduction",
					description: "Basics of Python programming",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "javascript-es6",
			title: "JavaScript ES6+",
			description: "Modern JavaScript with ES6 features and beyond",
			level: "Intermediate",
			estimatedHours: 30,
			hasProtectedContent: true,
			isFree: false,
			version: "ES2023",
			type: "course",
			exercises: [
				{
					id: "js-fundamentals",
					title: "JavaScript Fundamentals",
					description: "Core JavaScript concepts",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "data-structures-algorithms",
			title: "Data Structures & Algorithms",
			description: "Essential data structures and algorithms for interviews",
			level: "Advanced",
			estimatedHours: 50,
			hasProtectedContent: true,
			isFree: false,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "ds-intro",
					title: "Data Structures Introduction",
					description: "Overview of data structures",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "web-development",
			title: "Web Development Full Stack",
			description: "Complete web development course with frontend and backend",
			level: "Intermediate",
			estimatedHours: 60,
			hasProtectedContent: true,
			isFree: false,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "web-intro",
					title: "Web Development Introduction",
					description: "Basics of web development",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "machine-learning",
			title: "Machine Learning Fundamentals",
			description: "Introduction to machine learning concepts and algorithms",
			level: "Advanced",
			estimatedHours: 45,
			hasProtectedContent: true,
			isFree: false,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "ml-intro",
					title: "Machine Learning Introduction",
					description: "Basics of machine learning",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "docker-kubernetes",
			title: "Docker & Kubernetes",
			description: "Containerization and orchestration with Docker and Kubernetes",
			level: "Intermediate",
			estimatedHours: 35,
			hasProtectedContent: true,
			isFree: false,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "docker-intro",
					title: "Docker Introduction",
					description: "Basics of Docker containerization",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "react-native",
			title: "React Native Mobile Development",
			description: "Build cross-platform mobile apps with React Native",
			level: "Intermediate",
			estimatedHours: 40,
			hasProtectedContent: true,
			isFree: false,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "react-intro",
					title: "React Native Introduction",
					description: "Basics of React Native",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "sql-database",
			title: "SQL & Database Design",
			description: "Database design and SQL query optimization",
			level: "Beginner",
			estimatedHours: 25,
			hasProtectedContent: false,
			isFree: true,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "sql-intro",
					title: "SQL Introduction",
					description: "Basics of SQL",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		},
		{
			id: "git-version-control",
			title: "Git Version Control",
			description: "Master Git for version control and collaboration",
			level: "Beginner",
			estimatedHours: 15,
			hasProtectedContent: false,
			isFree: true,
			version: "2023",
			type: "course",
			exercises: [
				{
					id: "git-intro",
					title: "Git Introduction",
					description: "Basics of Git",
					type: "exercise",
					folders: [],
					files: []
				}
			]
		}
	]
};