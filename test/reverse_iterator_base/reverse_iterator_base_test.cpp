#include "../../source/reverse_iterator_base/reverse_iterator_base.h"
#include "../catch.hpp"

SCENARIO("reverse iterator can be cast back to its template parameter type",
	 "[reverse-iterator]"){

  GIVEN("reverse iterator construced with integer"){
    tc::reverse_iterator_base<int> rev_iter(42);

    WHEN("it is cast back to integer"){
      THEN("the result is the same integer"){
	REQUIRE((int)rev_iter == 42);
      }
    }
  }
}

SCENARIO("reverse iterators can be compared",
	 "[reverse-iterator]"){

  GIVEN("reverse iterators construced with the same integer"){
    tc::reverse_iterator_base<int> rev_iter1(42);
    tc::reverse_iterator_base<int> rev_iter2(42);

    WHEN("they are compared with =="){
      THEN("the result is true"){
	REQUIRE(rev_iter1 == rev_iter2);
      }
    }

    WHEN("they are compared with !="){
      THEN("the result is false"){
	REQUIRE_FALSE(rev_iter1 != rev_iter2);
      }
    }
  }

  GIVEN("reverse iterators construced with different integer"){
    tc::reverse_iterator_base<int> rev_iter1(42);
    tc::reverse_iterator_base<int> rev_iter2(13);

    WHEN("they are compared with =="){
      THEN("the result is false"){
	REQUIRE_FALSE(rev_iter1 == rev_iter2);
      }
    }

    WHEN("they are compared with !="){
      THEN("the result is true"){
	REQUIRE(rev_iter1 != rev_iter2);
      }
    }
  }
}

SCENARIO("reverse iterator can be prefix incremented and decremented",
	 "[reverse-iterator]"){

  GIVEN("reverse iterator"){
    tc::reverse_iterator_base<int> rev_iter(42);

    WHEN("prefix incremented"){
      auto ret_iter= ++rev_iter;

      THEN("the returned value and the iterator are the same"){
	REQUIRE(ret_iter == rev_iter);
	AND_THEN("the value stored in the iterator is decremented"){
	  REQUIRE((int)rev_iter == 41);
	}
      }
    }

    WHEN("prefix decremented"){
      auto ret_val = --rev_iter;
      THEN("the returned value and the iterator are the same"){
	REQUIRE(ret_val == rev_iter);
	AND_THEN("the value stored in the iterator is incremented"){
	  REQUIRE((int)rev_iter == 43);
	}
      }
    }
  }
}

SCENARIO("reverse iterator can be sufix incremented and decremented",
	 "[reverse-iterator]"){

  GIVEN("reverse iterator"){
    tc::reverse_iterator_base<int> rev_iter(42);

    WHEN("sufix incremented"){
      auto ret_val = rev_iter++;
      THEN("the returned value and the iterator are different"){
	REQUIRE(ret_val != rev_iter);
	AND_THEN("the value stored in the iterator is decremented while the value in the resturned iterator is not changed")
	{
	  REQUIRE((int)rev_iter == 41);
	  REQUIRE((int)ret_val == 42);
	}
      }
    }

    WHEN("prefix decremented"){
      auto ret_val = rev_iter--;
      THEN("the returned value and the iterator are the same"){
	REQUIRE(ret_val != rev_iter);
	AND_THEN("the value stored in the iterator is incremented while the value in the resturned iterator is not changed")
	{
	  REQUIRE((int)rev_iter == 43);
	  REQUIRE((int)ret_val == 42);
	}
      }
    }
  }
}
