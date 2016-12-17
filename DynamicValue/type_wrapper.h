#pragma once
#include <type_traits>

namespace dynamic_value
{
	class Type
	{
		typedef void type;
	public:
		virtual ~Type() {}

		virtual bool operator == (const Type& rhs) const {
			return false;
		}

	private:
	};

	namespace detail
	{
		template <typename T>
		class TypeImpl : public Type
		{
		public:
			bool operator == (const Type& rhs) const override {
				return false;
			}
		};
	}
}