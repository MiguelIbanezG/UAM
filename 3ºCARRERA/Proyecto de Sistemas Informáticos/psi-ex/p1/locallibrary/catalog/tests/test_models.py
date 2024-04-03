from django.test import TestCase

from catalog.models import Author, Book, Genre, Language, BookInstance


class AuthorModelTest(TestCase):
    @classmethod
    def setUpTestData(cls):
        # Set up non-modified objects used by all test methods
        Author.objects.create(first_name='Big', last_name='Bob', id=1)

    def test_first_name_label(self):
        author = Author.objects.get(id=1)
        field_label = author._meta.get_field('first_name').verbose_name
        self.assertEqual(field_label, 'first name')

    def test_last_name_label(self):
        author = Author.objects.get(id=1)
        field_label = author._meta.get_field('last_name').verbose_name
        self.assertEqual(field_label, 'last name')

    def test_date_of_birth_label(self):
        author = Author.objects.get(id=1)
        field_label = author._meta.get_field('date_of_birth').verbose_name
        self.assertEqual(field_label, 'birth')

    def test_date_of_death_label(self):
        author = Author.objects.get(id=1)
        field_label = author._meta.get_field('date_of_death').verbose_name
        self.assertEqual(field_label, 'died')

    def test_first_name_max_length(self):
        author = Author.objects.get(id=1)
        max_length = author._meta.get_field('first_name').max_length
        self.assertEqual(max_length, 100)

    def test_object_name_is_last_name_comma_first_name(self):
        author = Author.objects.get(id=1)
        expected_object_name = f'{author.last_name}, {author.first_name}'
        self.assertEqual(str(author), expected_object_name)

    def test_get_absolute_url(self):
        author = Author.objects.get(id=1)
        # This will also fail if the urlconf is not defined.
        self.assertEqual(author.get_absolute_url(), '/catalog/author/1')


class BookModelTest(TestCase):
    @classmethod
    def setUpTestData(cls):
        # Create a book
        test_author = Author.objects.create(
            first_name='John', last_name='Smith', id=1)
        test_genre = Genre.objects.create(name='Fantasy')
        test_language = Language.objects.create(name='English')
        test_book = Book.objects.create(
            title='Book Title',
            summary='My book summary',
            isbn='ABCDEFG',
            author=test_author,
            language=test_language,
            id=1,
        )

        # Create genre as a post-step
        test_book.genre.add(test_genre)
        test_book.save()

    def test_Book_title(self):
        book = Book.objects.get(id=1)

        field_dscr = str(book)
        self.assertEqual(field_dscr, 'Book Title')

    def test_Book_genre_short_description(self):
        book = Book.objects.get(id=1)

        field_dscr = book.display_genre.short_description
        self.assertEqual(field_dscr, 'Genre')

    def test_Book_displaygenre(self):
        book = Book.objects.get(id=1)
        field_dscr = book.display_genre()

        self.assertEqual(field_dscr, 'Fantasy')

    def test_get_absolute_url(self):
        book = Book.objects.get(id=1)
        # This will also fail if the urlconf is not defined.
        self.assertEqual(book.get_absolute_url(), '/catalog/book/1')


class BookInstanceModelTest(TestCase):
    @classmethod
    def setUpTestData(cls):
        test_author = Author.objects.create(
            first_name='John', last_name='Smith')
        test_genre = Genre.objects.create(name='Fantasy')
        test_language = Language.objects.create(name='English')
        test_book = Book.objects.create(
            id=1,
            title='Book Title',
            summary='My book summary',
            isbn='ABCDEFG',
            author=test_author,
            language=test_language,
        )
        BookInstance.objects.create(
            book=test_book,
            imprint='Unlikely Imprint, 2016',
            due_back=None,
            borrower=None,
            status='a',
            id=int(1),
        )

    def test_BookInstance_str_(self):
        bookinstance = BookInstance.objects.get(id=1)
        self.assertEqual(str(bookinstance), '1 (Book Title)')
