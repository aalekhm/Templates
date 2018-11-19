
// - Any number of combo types.
// - No type information needed at runtime.
// - 'get<n>' function lets us access the nth element of the tuple.

namespace VariadicTemplates
{
	// Incomplete declaration of Tuple template
	template <typename... Ttypes>
	class Tuple;//  ^
	//				|___________________________ Variadic parameter pack.

	// Empty Tuple (base case)
	template <>
	class Tuple<>
	{
		/* empty */
	};

	// --------------------------------------------------------------
	// Incomplete declaration
	template <size_t idx, typename Ttuple>
	struct TupleElement;

	// Base case
	// Access the 0th(first) element
	template <typename Tthis, typename... Trest>
	struct TupleElement< 0, Tuple<Tthis, Trest...> >
	{
		/*
		// 'using' => Similar to 'typedef'(s)
		// 'typedef' => Its a way to refer to something by a different name.
		// Since 'typedef'(s) dont work with templates, we have to use 'using'.
		using type_t = Tvalue;							// Type of the value at this index.
		using TupleType_t = Tuple<Tvalue, Trest...>;	// 'TupleType_t' is a tuple with TypeType_t::value
														// having the type 'type_t'
		*/
		// Or
		typedef Tthis type_t;
		typedef Tuple<Tthis, Trest...> TupleType_t;
	};

	// recursive TupleElement definition
	template <size_t idx, typename Tthis, typename... Trest>
	struct TupleElement< idx, Tuple<Tthis, Trest...> >
	: 
	public TupleElement< idx - 1, Tuple<Trest...> >
	{
		/* empty */
	};

	// --------------------------------------------------------------
	// Usage: get<1>(tuple) = 'A'
	// get function to access the idxth element in the tuple
	template <size_t idx, typename... Ttypes>						// template
	typename TupleElement< idx, Tuple<Ttypes...> >::type_t&			// return type, check the '&' which returns the type as a reference.
	get(Tuple<Ttypes...>& tuple)
	{
		//using TupleType_t = typename TupleElement< idx, Tuple<Ttypes...> >::TupleType_t;
		// Or
		typedef typename TupleElement< idx, Tuple<Ttypes...> >::TupleType_t TupleType_t;	// This is typedef'ed just so that it is used in the next line
																							// for a static cast.

		//return static_cast<TupleType_t&>(tuple)._Myfirst;									// Notice the return type, it uses the type typedef defined above.
		// Or																				// Similarly, the tuple is cast to the 'TupleType_t' typedef defined above 
																							// and then we access the _Myfirst member (which represents the value).
		return ((TupleType_t&) tuple)._Myfirst;
	}

	// recursive Tuple definition
	template <typename Tthis, typename... Trest>
	class Tuple<Tthis, Trest...> : public Tuple<Trest...>		// The recursive specialization uses inheritance so that we'll end up 
	{															// with members of every argument tyoe specified by the tuple.
		public:
			Tthis _Myfirst;
	};

	/*
		|-----------------------------------|
		|			std::string				|
		|		Tuplae<std::string>			|	==> Tuple<Tthis, Trest>	==> Tuple< Tthis, Tuple<> >
		|-----------------------------------|		==> Tthis = std::string & Trest = Tuple<> 
		|				char				|
		|		Tuple<char, std::string>	|	==> Tuple<Tthis, Trest>	==> Tuple< Tthis, Tuple<std::string> >
		|-----------------------------------|		==> Tthis = char & Trest = Tuple<std::string>
		|				int					|
		|	Tuple<int, char, std::string>	|	==> Tuple<Tthis, Trest>	==> Tuple< tthis, Tuple<char, string> >
		|___________________________________|		==> Tthis = int & Trest = Tuple<char, std::string>
	*/

	//// function to fill the tuple with values ////
	// Done case
	template <size_t idx, typename Ttuple>
	void fillTuple(Ttuple& toFill) { };

	// recursive definition
	template <size_t idx, typename Ttuple, typename Tfirst, typename... Trest>
	void fillTuple(Ttuple& toFill, const Tfirst& first, Trest... rest)
	{
		get<idx>(toFill) = first;
		fillTuple<idx + 1>(toFill, rest...);
	};

	//// Create  a tuple from values ////
	template <typename... Ttypes>				// template
	Tuple<Ttypes...>							// return type
	makeTuple(Ttypes... args)					// function itself
	{
		Tuple<Ttypes...> result;
		fillTuple<0>(result, args...);

		return result;
	}
}