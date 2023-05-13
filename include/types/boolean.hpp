#ifndef BOOLEAN_HPP
#define BOOLEAN_HPP

namespace iwbs
{
    class Boolean
    {
        public:
            Boolean();
            Boolean(bool value);
            ~Boolean();
            void setValue(bool value);
            bool getValue() const;
        private:
            bool value;
    };
}

#endif